#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
const int MOD = 51061;
const int INF = 1000000001;
struct SegTree {
  int N;
  int v[MAXN << 3];
  SegTree() {
    N = 1;
    memset(v, 0, sizeof(v));
  }
  void modify(int p, int x) {
    for (v[p += N] = x; p ^ 1; p >>= 1) v[p >> 1] = max(v[p ^ 1], v[p]);
  }
  int query(int x) {
    int ret = 0;
    for (x += N; x ^ 1; x >>= 1)
      if (~x & 1) ret = max(ret, v[x ^ 1]);
    return ret;
  }
} T1, T2;
int val[MAXN], pos[MAXN];
priority_queue<int, vector<int>, greater<int> > q;
void plant(int p, int h) {
  q.push(p);
  val[pos[h] = p] = h;
  for (int i = max(h - 10, 0); i < h; i++)
    if (pos[i]) T1.modify(pos[i], 0);
  for (int i = h; i >= max(h - 10, 0); i--)
    if (pos[i]) {
      int tmp = T1.query(pos[i]) + 1;
      T1.modify(pos[i], tmp);
      T2.modify(i, tmp);
    }
}
void cut(int x) {
  int w[16];
  for (int i = 0; i < x; i++) {
    T2.modify(val[w[i] = q.top()], 0);
    q.pop();
  }
  T1.modify(w[x - 1], 0);
  pos[val[w[x - 1]]] = 0;
  val[w[x - 1]] = 0;
  for (int i = x - 2; i >= 0; i--) {
    int tmp = T2.query(val[w[i]]) + 1;
    T1.modify(w[i], tmp);
    T2.modify(val[w[i]], tmp);
    q.push(w[i]);
  }
}
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  while (T1.N < n + 1) T1.N <<= 1;
  while (T2.N < m + 11) T2.N <<= 1;
  for (int i = 1; i <= m; i++) {
    int type, x, v;
    cin >> type;
    if (type == 1) {
      cin >> x >> v;
      plant(x, v + m - i);
    } else {
      cin >> x;
      cut(x);
    }
    cout << T1.v[1] << endl;
  }
  return 0;
}
