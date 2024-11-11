#include <bits/stdc++.h>
using namespace std;
inline void fileio(const char* in, const char* out) {
  freopen(in, "r", stdin);
  freopen(out, "w", stdout);
}
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<ll> VL;
const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld EPS = 1e-9, PI = acos(-1);
const int N = 405;
int nx[N][26];
int dp[N][N];
int works(const string& a, const string& b) {
  memset(dp, INF, sizeof dp);
  {};
  dp[0][0] = -1;
  for (int i = 0; i <= a.size(); ++i) {
    for (int j = 0; j <= b.size(); ++j) {
      if (i && dp[i - 1][j] != INF) {
        int temp = nx[dp[i - 1][j] + 1][a[i - 1] - 'a'];
        if (temp != -1) dp[i][j] = min(temp, dp[i][j]);
      }
      if (j && dp[i][j - 1] != INF) {
        int temp = nx[dp[i][j - 1] + 1][b[j - 1] - 'a'];
        if (temp != -1) dp[i][j] = min(temp, dp[i][j]);
      }
      {};
    }
  }
  return dp[a.size()][b.size()];
}
void deal(int T) {
  string s, t;
  cin >> s >> t;
  {};
  const int n = s.size();
  memset(nx, -1, sizeof nx);
  for (int i = n; i--;) {
    memcpy(nx[i], nx[i + 1], sizeof(nx[i]));
    nx[i][s[i] - 'a'] = i;
  }
  {
    int i = -1;
    for (char c : t) {
      i = nx[i + 1][c - 'a'];
      if (i == -1) {
        break;
      }
    }
    if (i != -1) {
      cout << "YES\n";
      return;
    }
  }
  for (int i = 1; i < t.size() - 1; ++i) {
    string a = t.substr(0, i);
    string b = t.substr(i);
    if (works(a, b) < n) {
      {};
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  atexit([]() { cerr << "Time: " << (ld)clock() / CLOCKS_PER_SEC << nl; });
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(12);
  int T;
  cin >> T;
  {};
  for (int i = 0; i < (T); ++i) deal(i);
  return 0;
}
