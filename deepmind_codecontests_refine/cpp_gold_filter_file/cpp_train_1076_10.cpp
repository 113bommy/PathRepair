#include <bits/stdc++.h>
using namespace std;
const int MOD(1000000007);
const int INF((1 << 30) - 1);
const int MAXN(100005);
int a[MAXN];
long long power[MAXN], p = MOD, h[MAXN];
map<int, int> b, d;
vector<int> pos[MAXN];
struct repeat {
  int len, pos;
  repeat(int l, int p) {
    len = l;
    pos = p;
  }
  bool operator<(const repeat &p) const {
    if (len != p.len) return len > p.len;
    return pos > p.pos;
  }
};
priority_queue<repeat> q;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    d[a[i]] = 1;
  }
  int num = 0;
  for (typeof(d.begin()) it = d.begin(); it != d.end(); it++)
    b[it->first] = (++num);
  for (int i = 0; i < n; i++) {
    int t = b[a[i]];
    pos[t].push_back(i);
  }
  power[0] = 1;
  for (int i = 1; i <= n; i++) power[i] = power[i - 1] * p;
  for (int i = 0; i < n; i++) {
    h[i] = power[i] * a[i];
    if (i > 0) h[i] += h[i - 1];
  }
  for (int i = 1; i <= num; i++) {
    int l = pos[i].size();
    for (int j = 0; j <= l - 2; j++)
      for (int k = j + 1; k <= l - 1; k++) {
        int len = pos[i][k] - pos[i][j];
        if (pos[i][k] + len - 1 >= n) continue;
        long long h1 = h[pos[i][k] + len - 1] - h[pos[i][k] - 1];
        long long h2 = h[pos[i][j] + len - 1];
        if (pos[i][j] > 0) h2 -= h[pos[i][j] - 1];
        h2 *= power[len];
        if (h1 == h2) q.push(repeat(len, pos[i][k]));
      }
  }
  int nowpos = 0;
  while (!q.empty()) {
    int len = q.top().len, position = q.top().pos;
    q.pop();
    if (position - len < nowpos) continue;
    nowpos = position;
  }
  printf("%d\n", n - nowpos);
  for (int i = nowpos; i <= n - 1; i++) printf("%d ", a[i]);
}
