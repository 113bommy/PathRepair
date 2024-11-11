#include <bits/stdc++.h>
using namespace std;
int n, u, r, b[35], k[35], p[35];
long long ans(vector<int> c) {
  long long ret = 0;
  for (int i = 1; i <= n; i++) ret += c[i] * k[i];
  return ret;
}
inline vector<int> xo(vector<int> c) {
  for (int i = 1; i <= n; i++) c[i] = c[i] ^ b[i];
  return c;
}
inline vector<int> tr(vector<int> c) {
  vector<int> ne(n + 1);
  for (int i = 1; i <= n; i++) ne[i] = c[p[i]] + r;
  return ne;
}
long long go(int l, vector<int> c, int d) {
  if (l == 0) return ans(c);
  long long ret = go(l - 1, tr(c), 0);
  if (l % 2 == 0) ret = max(ret, ans(c));
  if (!d) ret = max(ret, go(l - 1, xo(c), 1));
  return ret;
}
int main() {
  cin >> n >> u >> r;
  vector<int> c(n + 1);
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) cin >> k[i];
  for (int i = 1; i <= n; i++) cin >> p[i];
  cout << go(u, c, 0);
  return 0;
}
