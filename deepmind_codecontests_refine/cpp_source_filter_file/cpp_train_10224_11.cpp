#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0', c = getchar();
  return x * f;
}
struct seg {
  int ls[N * 20], rs[N * 20];
  int siz[N * 20], scnt;
  void insert(int &pos, int pre, int v, int l, int r) {
    pos = ++scnt;
    siz[pos] = siz[pre];
    ls[pos] = ls[pre];
    rs[pos] = rs[pos];
    siz[pos]++;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (v <= mid) {
      insert(ls[pos], ls[pre], v, l, mid);
    } else
      insert(rs[pos], rs[pre], v, mid + 1, r);
  }
  int query(int pos, int k, int l, int r) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (siz[ls[pos]] < k)
      return query(rs[pos], k - siz[ls[pos]], mid + 1, r);
    else
      return query(ls[pos], k, l, mid);
  }
} t;
int rt[N];
int main() {
  int n, m;
  cin >> n;
  vector<int> a(n + 1);
  vector<pair<int, int> > b(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i], b[i] = {a[i], i};
  sort(b.begin() + 1, b.end(), [&](pair<int, int> x, pair<int, int> y) {
    return x.first == y.first ? x.second < y.second : x.first > y.first;
  });
  for (int i = 1; i <= n; i++) t.insert(rt[i], rt[i - 1], b[i].second, 1, n);
  cin >> m;
  while (m--) {
    int k = read(), j = read();
    cout << a[t.query(rt[k], j, 1, n)] << endl;
  }
}
