#include <bits/stdc++.h>
using namespace std;
template <typename T>
string to_string(const pair<T, T>& pr) {
  return "(" + to_string(pr.first) + "," + to_string(pr.second) + ")";
}
template <typename T>
string to_string(const vector<T>& vc, int w) {
  if (vc.empty()) return "";
  if (w + 1 == vc.size()) return to_string(vc[w]);
  return to_string(vc[w]) + "," + to_string(vc, w + 1);
}
template <typename T>
string to_string(const vector<T>& vc) {
  return "{" + to_string(vc, 0) + "}";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
class DebugStream {
} LOG;
template <typename T>
DebugStream& operator<<(DebugStream& s, const T&) {
  return s;
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int maxN = 1.4e5 + 9, maxV = 1e6 + 9, MOD = 1e9 + 7, SQ = 335, lg = 20,
          bs = 29;
int dp[maxN << 1][4];
int vi[maxN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp, -1, sizeof dp);
  int n, k;
  cin >> n >> k;
  int N = 1 << n;
  for (int i = 0, inp; i < k; i++) {
    cin >> inp;
    vi[inp - 1] = 1;
  }
  for (int i = N / 2; i < N; i++) {
    int le = i * 2 - N, ri = i * 2 + 1 - N;
    int isg = (vi[le] || vi[ri]);
    dp[i][vi[le] + vi[ri] * 2] = isg;
    dp[i][vi[ri] + vi[le] * 2] = isg;
  }
  for (int i = N / 2 - 1; i >= 1; i--) {
    int le = i * 2, ri = i * 2 + 1;
    for (int a = 0; a < 4; a++) {
      if (dp[le][a] == -1) continue;
      for (int b = 0; b < 4; b++) {
        if (dp[ri][b] == -1) continue;
        int blu = (a % 2 || b % 2);
        int prf = dp[le][a] + dp[ri][b] + blu + (a | b) / 2;
        for (int r = 0; r < 2; r++, swap(a, b)) {
          int cnd = (b / 2 || blu);
          int& toc = dp[i][cnd + (a & 2)];
          toc = max(toc, prf + cnd);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 4; i++) ans = max(ans, dp[1][i] + (i ? 1 : 0));
  cout << ans << '\n';
}
