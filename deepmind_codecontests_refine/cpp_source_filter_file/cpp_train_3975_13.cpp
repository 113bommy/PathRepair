#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int prime = 9241;
struct segment {
  long long s, f;
  segment() {}
  segment(long long s, long long f) : s(s), f(f) {}
  int size() { return (int)(f - s + 1); }
  bool inrng(long long a) { return a >= s && a <= f; }
};
struct lnk {
  int day, p;
  lnk() {}
  lnk(int day, int p) : day(day), p(p){};
};
vector<int> c;
vector<segment> rng;
long long dp[51][51][101];
lnk h[51][51][101];
bool ls(int a, int b) { return c[a] < c[b]; }
int main() {
  int n, m, k_;
  cin >> n >> m >> k_;
  c.resize(m);
  rng.resize(m);
  for (int i = 0; i < m; i++) cin >> rng[i].s >> rng[i].f >> c[i];
  vector<int> nms(m);
  for (int i = 0; i < m; i++) nms[i] = i;
  sort(nms.begin(), nms.end());
  for (int j = 0; j < m; j++)
    for (int i = 0; i < rng[nms[j]].size(); i++) {
      dp[j][0][i] = rng[nms[0]].s + (long long)i;
      h[j][0][i] = lnk(-1, -1);
    }
  for (int i = 0; i < m - 1; i++)
    for (int j = 0; j < n - 1; j++)
      for (int k = 0; k < rng[nms[i]].size(); k++)
        if (dp[i][j][k] != 0) {
          int nj = j + 1;
          for (int ni = i + 1; ni < m; ni++) {
            if (c[nms[ni]] <= c[nms[i]]) continue;
            long long nk = ((long long)k_ + (long long)k + rng[nms[i]].s);
            if (rng[nms[ni]].inrng(nk)) {
              int nnk = (int)(nk - rng[nms[ni]].s);
              if (dp[ni][nj][nnk] < dp[i][j][k] + nk) {
                dp[ni][nj][nnk] = dp[i][j][k] + nk;
                h[ni][nj][nnk] = lnk(i, k);
              }
            }
            nk = ((long long)k_ * ((long long)k + rng[nms[i]].s));
            if (rng[nms[ni]].inrng(nk)) {
              int nnk = (int)(nk - rng[nms[ni]].s);
              if (dp[ni][nj][nnk] < dp[i][j][k] + nk) {
                dp[ni][nj][nnk] = dp[i][j][k] + nk;
                h[ni][nj][nnk] = lnk(i, k);
              }
            }
          }
        }
  int maxk = -1;
  int maxm = -1;
  for (int j = 0; j < m; j++)
    for (int i = 0; i < rng[nms[j]].size(); i++)
      if (maxk == -1 || maxm == -1 || dp[j][n - 1][i] > dp[maxm][n - 1][maxk]) {
        maxk = i;
        maxm = j;
      }
  if (dp[maxm][n - 1][maxk] == 0) {
    cout << "NO";
  } else {
    cout << "YES" << endl;
    int nn = n - 1;
    int mm = maxm;
    int kk = maxk;
    vector<int> ans0(n);
    vector<long long> ans1(n);
    for (; nn >= 0; nn--) {
      ans0[nn] = nms[mm];
      ans1[nn] = rng[nms[mm]].s + (long long)kk;
      int nmm = h[mm][nn][kk].day;
      int nkk = h[mm][nn][kk].p;
      mm = nmm;
      kk = nkk;
    }
    for (int i = 0; i < n; i++) cout << ans0[i] + 1 << ' ' << ans1[i] << endl;
  }
}
