#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long Hashimoto = 0;
  bool Kanna = 1;
  char I_Love = getchar();
  while (I_Love < '0' || I_Love > '9') {
    if (I_Love == '-') Kanna = 0;
    I_Love = getchar();
  }
  while (I_Love >= '0' && I_Love <= '9') {
    Hashimoto = Hashimoto * 10 + I_Love - '0';
    I_Love = getchar();
  }
  return (Kanna ? Hashimoto : -Hashimoto);
}
template <typename T1, typename T2>
inline void Umax(T1 &a, T2 b) {
  if (a < b) a = b;
}
template <typename T1, typename T2>
inline void Umin(T1 &a, T2 b) {
  if (a > b) a = b;
}
int nf, ne, ns;
int rf, re, rs;
int df, de;
int ra;
bool iss[20][2];
long double ans = 0;
vector<pair<long double, long double> > can, cand;
vector<long double> sav;
int dist[888];
int fl[20][2], fr[20][2];
int el[20][2], er[20][2];
int sl[20][2], sr[20][2];
long double dp[22][22];
void solve() {
  cand.clear();
  for (int i = 0; i < (sav.size()); ++i) dist[i] = 1;
  for (int i = 0; i < (ra); ++i)
    for (int j = 0; j < (2); ++j) {
      if (iss[i][j]) {
        for (int k = sl[i][j]; k < (sr[i][j]); ++k) {
          dist[k]++;
        }
      }
    }
  for (int i = 0; i < (ra); ++i)
    for (int j = 0; j < (2); ++j) {
      if (!iss[i][j]) {
        long double val = 0;
        for (int k = fl[i][j]; k < (fr[i][j]); ++k) {
          val += df * dist[k] * (sav[k + 1] - sav[k]);
        }
        cand.push_back(make_pair(val, 0));
        val = 0;
        for (int k = el[i][j]; k < (er[i][j]); ++k) {
          val += de * dist[k] * (sav[k + 1] - sav[k]);
        }
        cand[cand.size() - 1].second = val;
      }
    }
  for (int i = 0; i < (22); ++i)
    for (int j = 0; j < (22); ++j) dp[i][j] = -(int)1e9;
  dp[nf + ne][nf] = 0;
  for (int i = cand.size(); i > 0; i--)
    for (int j = 0; j < (22); ++j)
      if (dp[i][j] >= -1) {
        if (j) {
          Umax(dp[i - 1][j - 1], dp[i][j] + cand[i - 1].first);
        }
        if (nf + ne - i - (nf - j) < ne) {
          Umax(dp[i - 1][j], dp[i][j] + cand[i - 1].second);
        }
      }
  Umax(ans, dp[0][0]);
}
void dfs(int x, int y, int cnt) {
  if (x == ra) {
    if (cnt == ns) solve();
    return;
  }
  if (y == 2) {
    dfs(x + 1, 0, cnt);
    return;
  }
  if (ra + ra - x - x - y + cnt > ns) {
    dfs(x, y + 1, cnt);
  }
  if (cnt < ns) {
    iss[x][y] = 1;
    dfs(x, y + 1, cnt + 1);
    iss[x][y] = 0;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> nf >> ne >> ns;
  cin >> rf >> re >> rs;
  cin >> df >> de;
  ra = (nf + ne + ns + 1) / 2;
  long double f = sqrt((long double)(rf) * (rf)-1);
  long double e = sqrt((long double)(re) * (re)-1);
  long double s = sqrt((long double)(rs) * (rs)-1);
  for (int i = 0; i < (20); ++i)
    for (int j = 0; j < (2); ++j) {
      sav.push_back(i - f);
      sav.push_back(i + f);
      sav.push_back(i - e);
      sav.push_back(i + e);
      sav.push_back(i - s);
      sav.push_back(i + s);
    }
  sort(sav.begin(), sav.end());
  ;
  sav.erase(unique(sav.begin(), sav.end()), sav.end());
  ;
  for (int i = 0; i < (20); ++i)
    for (int j = 0; j < (2); ++j) {
      fl[i][j] = lower_bound(sav.begin(), sav.end(), i - f) - sav.begin();
      fr[i][j] = lower_bound(sav.begin(), sav.end(), i + f) - sav.begin();
      el[i][j] = lower_bound(sav.begin(), sav.end(), i - e) - sav.begin();
      er[i][j] = lower_bound(sav.begin(), sav.end(), i + e) - sav.begin();
      sl[i][j] = lower_bound(sav.begin(), sav.end(), i - s) - sav.begin();
      sr[i][j] = lower_bound(sav.begin(), sav.end(), i + s) - sav.begin();
    }
  dfs(0, 0, 0);
  printf("%.10Lf\n", ans);
  return 0;
}
