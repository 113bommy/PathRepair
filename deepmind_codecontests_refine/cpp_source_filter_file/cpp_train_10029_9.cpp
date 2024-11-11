#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long base = 1e9 + 7;
const long long oo = 1e6 + 10;
const long long gh = 1e3 + 3;
const long long inf = 1e15 + 5;
long long n, m, k, q;
bool maximize(long long &a, long long b) {
  if (a < b)
    a = b;
  else
    return false;
  return true;
}
bool minimize(long long &a, long long b) {
  if (a > b)
    a = b;
  else
    return false;
  return true;
}
string s[oo];
long long a[oo];
pair<long long, long long> pa[oo];
vector<long long> con[oo];
long long res = 0;
long long sum[oo];
long long scol[oo];
pair<long long, long long> dp[2002][2002];
string ss;
struct edge {
  long long x;
  long long y;
  long long gt;
} ed[oo];
long long vtx[27][2002];
set<long long> vttx[2002][27];
void input() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> s[i];
  }
  cin >> m;
  for (long long i = 1; i <= m; i++) {
    cin >> a[i];
  }
  cin >> ss;
}
void prepare() {
  for (long long i = 1; i <= n; i++)
    for (long long j = 0; j < s[i].length(); ++j) {
      vttx[i][s[i][j] - 'a'].insert(j);
    }
  for (long long i = 0; i < 27; ++i) vtx[m + 1][i] = inf;
  for (long long i = m; i >= 0; i--) {
    for (long long j = 0; j < 27; ++j) {
      if (vttx[a[i]][j].size())
        vtx[i][j] = i;
      else
        vtx[i][j] = vtx[i + 1][j];
    }
  }
}
void proceduce() {
  for (long long j = 1; j <= ss.length(); j++) dp[0][j] = {inf, 0};
  for (long long i = 0; i < ss.length(); i++) {
    ss[i] -= 'a';
    for (long long j = 1; j <= ss.length(); ++j) {
      dp[i + 1][j] = dp[i][j];
      pair<long long, long long> vtm;
      if (dp[i][j - 1].first == inf) {
        continue;
      }
      long long t = vtx[dp[i][j - 1].first][ss[i]];
      if (t == inf) continue;
      if (t == dp[i][j - 1].first) {
        set<long long>::iterator it =
            vttx[a[t]][ss[i]].upper_bound(dp[i][j - 1].second);
        if (it != vttx[a[t]][ss[i]].end()) {
          vtm = {t, *it};
        } else {
          t = vtx[dp[i][j - 1].first + 1][ss[i]];
          if (t != inf) vtm.second = *vttx[a[t]][ss[i]].begin();
          vtm.first = t;
        }
      } else {
        if (vttx[a[t]][ss[i]].size() != 0)
          vtm.second = *vttx[a[t]][ss[i]].begin();
        vtm.first = t;
      }
      dp[i + 1][j] = min(dp[i + 1][j], vtm);
      if (dp[i + 1][j].first <= n) res = max(res, j);
    }
  }
}
void solve() {
  prepare();
  proceduce();
}
void ouput() { cout << res; }
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (ifstream("test.txt")) {
    freopen("test.txt", "r", stdin);
  } else if (ifstream(""
                      ".inp")) {
    freopen(
        ""
        ".inp",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  }
  input();
  solve();
  ouput();
}
