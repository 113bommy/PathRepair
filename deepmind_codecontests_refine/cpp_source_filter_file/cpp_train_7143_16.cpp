#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const long long ooo = 9223372036854775807ll;
const int _cnt = 1000 * 1000 + 7;
const int _p = 1000 * 1000 * 1000 + 7;
const int N = 3005;
const double PI = acos(-1.0);
const double eps = 1e-9;
int o(int x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void file_put() {
  freopen("filename.in", "r", stdin);
  freopen("filename.out", "w", stdout);
}
int n, m, q, flag = 0, v[N], x, y, k, ans[400105], c[N];
vector<int> V[N], r;
vector<pair<int, int> > Q[N][N];
void dfs(int s, int x) {
  v[x] = 2 * s - 1, r.push_back(x);
  for (__typeof((Q[s][x]).begin()) it = (Q[s][x]).begin();
       it != (Q[s][x]).end(); it++)
    if (!flag && it->second <= r.size()) ans[it->first] = r[it->second - 1];
  for (__typeof((V[x]).begin()) it = (V[x]).begin(); it != (V[x]).end(); it++)
    if (v[*it] < 2 * s - 1)
      dfs(s, *it);
    else if (v[*it] == 2 * s - 1)
      flag++, c[*it]++;
  flag -= c[x], c[x] = 0;
  r.pop_back(), v[x] = 2 * x;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = (1); i <= (m); ++i) scanf("%d%d", &x, &y), V[x].push_back(y);
  for (int i = (1); i <= (q); ++i)
    scanf("%d%d%d", &x, &y, &k), Q[x][y].push_back(make_pair(i, k)),
        ans[i] = -1;
  for (int i = (1); i <= (n); ++i) sort((V[i]).begin(), (V[i]).end());
  for (int i = (1); i <= (n); ++i) dfs(i, i);
  for (int i = (1); i <= (q); ++i) printf("%d\n", ans[i]);
  return 0;
}
