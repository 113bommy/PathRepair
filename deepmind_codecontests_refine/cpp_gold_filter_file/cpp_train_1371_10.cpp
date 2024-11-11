#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize(3)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target("sse3", "sse2", "sse")
#pragma GCC target("avx", "sse4", "sse4.1", "sse4.2", "ssse3")
#pragma GCC target("f16c")
#pragma GCC optimize("inline", "fast-math", "unroll-loops", \
                     "no-stack-protector")
#pragma GCC push_options
#pragma GCC pop_options
#pragma GCC reset_options
#pragma GCC optimize("O3")
const double eps = 1e-9;
const int INFMEM = 63;
const int INF = 1061109567;
const long long LINF = 4557430888798830399LL;
const double DINF = numeric_limits<double>::infinity();
const long long MOD = 1000000007;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const double PI = 3.141592653589793;
inline void fastll(long long &input_number) {
  input_number = 0;
  int ch = getchar_unlocked();
  int sign = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') sign = -1;
    ch = getchar_unlocked();
  }
  while (ch >= '0' && ch <= '9') {
    input_number = (input_number << 3) + (input_number << 1) + ch - '0';
    ch = getchar_unlocked();
  }
  input_number *= sign;
}
inline void open(string a) {
  freopen((a + ".in").c_str(), "r", stdin);
  freopen((a + ".out").c_str(), "w", stdout);
}
inline void fasterios() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int n, m;
vector<pair<int, int> > ans;
void dfs(pair<int, int> st, pair<int, int> ed) {
  ans.push_back(st);
  if (st == ed) return;
  ans.push_back(ed);
  int d = -1;
  if ((st.first & 1)) d = 1;
  pair<int, int> nxst = {st.first, st.second + d};
  pair<int, int> nxed = {ed.first, ed.second - d};
  if (nxst.second > m || nxst.second < 1) {
    nxst = {st.first + 1, st.second};
    nxed = {ed.first - 1, ed.second};
  }
  if (nxst.first > nxed.first) return;
  if (nxst == ed) return;
  dfs(nxst, nxed);
}
int main() {
  cin >> n >> m;
  dfs({1, 1}, {n, m});
  for (int i = 0; i < n * m; i++)
    cout << ans[i].first << " " << ans[i].second << '\n';
  return 0;
}
