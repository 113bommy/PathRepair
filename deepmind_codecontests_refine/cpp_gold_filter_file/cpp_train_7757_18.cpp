#include <bits/stdc++.h>
using namespace std;
int inf_int = 2e9;
long long inf_ll = 2e18;
const double pi = 3.1415926535898;
template <typename T, typename T1>
void prin(vector<pair<T, T1> >& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i].first << " " << a[i].second << "\n";
  }
}
template <typename T>
void prin(vector<T>& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i];
    if (i < a.size() - 1)
      cout << " ";
    else
      cout << "\n";
  }
}
template <typename T>
void prin_new_line(vector<T>& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << "\n";
  }
}
template <typename T, typename T1>
void prin_new_line(vector<pair<T, T1> >& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i].first << " " << a[i].second << "\n";
  }
}
int sum_vec(vector<int>& a) {
  int s = 0;
  for (int i = 0; i < a.size(); i++) {
    s += a[i];
  }
  return s;
}
template <typename T>
T max(vector<T>& a) {
  T ans = a[0];
  for (int i = 1; i < a.size(); i++) {
    ans = max(ans, a[i]);
  }
  return ans;
}
template <typename T>
T min(vector<T>& a) {
  T ans = a[0];
  for (int i = 1; i < a.size(); i++) {
    ans = min(ans, a[i]);
  }
  return ans;
}
template <typename T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <typename T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
double s_triangle(double x1, double y1, double x2, double y2, double x3,
                  double y3) {
  return abs(((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2);
}
bool overflow(long long a, long long b) {
  if (a * b / b != a) return true;
  return false;
}
bool debug = 0;
const int maxn = 1e5 + 200;
long long mod = 1e9 + 7;
long long dp[4003][4003];
void solve() {
  int m, n;
  cin >> m >> n;
  string a;
  cin >> a;
  int mn = 0;
  int cur = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == '(') {
      cur++;
    } else {
      cur--;
    }
    mn = min(mn, cur);
  }
  dp[0][0] = 1;
  dp[1][1] = 1;
  for (int i = 2; i <= 3000; i++) {
    for (int e = 0; e <= 3000; e++) {
      dp[i][e] = dp[i - 1][e + 1];
      if (e) {
        dp[i][e] += dp[i - 1][e - 1];
      }
      dp[i][e] = dp[i][e] % mod;
    }
  }
  long long ans = 0;
  for (int i = 0; i <= m - n; i++) {
    for (int e = abs(mn); e <= m - n; e++) {
      long long x = dp[i][e];
      int b = e + cur;
      int len = m - n - i;
      if (e + cur >= 0 && len >= e + cur) {
        x = (x * dp[len][e + cur]) % mod;
        ans = (ans + x) % mod;
      }
    }
  }
  if (debug) cout << endl;
  cout << ans;
}
int main() {
  if (!debug) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  int t = 1;
  while (t--) solve();
  return 0;
}
