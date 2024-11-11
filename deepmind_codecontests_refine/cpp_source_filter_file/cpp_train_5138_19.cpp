#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int gi() {
  int w = 0;
  bool q = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') q = 0, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return q ? w : -w;
}
int v[N], x[N], y[N], m[N], len[N];
struct cmp {
  inline bool operator()(const int &a, const int &b) {
    return v[a] == v[b] ? a < b : v[a] < v[b];
  }
};
pair<int, int> ans[N << 2];
int main() {
  int n = gi(), i, k, all = 0, sum = 0, top = 0;
  set<int, cmp> s;
  set<int>::iterator it;
  for (i = 1; i <= n; i++)
    all += len[i] = gi(), v[i] = gi(), x[i] = gi(), y[i] = gi(), m[i] = gi(),
           s.insert(i);
  v[0] = 0;
  while (all--) {
    it = s.lower_bound(0);
    k = it == s.end() ? (sum++, *s.begin()) : *it;
    s.erase(k);
    v[0] = v[k];
    if (top < 200000) ans[++top] = make_pair(v[k], k);
    if (--len[k]) v[k] = (1LL * v[k] * x[k] + y[k]) % m[k], s.insert(k);
  }
  printf("%d\n", sum);
  if (top <= 200000)
    for (i = 1; i <= top; i++) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
