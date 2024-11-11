#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9);
const int MOD = int(1e9) + 7;
const long long N = 1000010;
const long long INFll = 1ll * INF * INF;
const long double INFld = 1e+018;
const long double EPS = 0.000000001;
const int sdx[4] = {-1, 0, 1, 0};
const int sdy[4] = {0, 1, 0, -1};
const long double PI = 3.1415926535897932384;
template <typename T>
ostream& operator<<(ostream& out, pair<T, T>& a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T>
istream& operator>>(istream& in, pair<T, T>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
  for (int i = 0; i < a.size(); ++i) in >> a[i];
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> a) {
  for (int i = 0; i < a.size(); ++i)
    if (i == a.size() - 1)
      out << a[i];
    else
      out << a[i] << " ";
  return out;
}
int dp[1010][1010][15][3];
void comp(int& a, int b) { a = max(a, b); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  string s, t;
  cin >> n >> m >> k >> s >> t;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++)
      for (int cnt = 0; cnt < k; cnt++)
        for (int x = 0; x < 2; x++) {
          comp(dp[i + 1][j][cnt][0], dp[i][j][cnt][x]);
          comp(dp[i][j + 1][cnt][0], dp[i][j][cnt][x]);
          if (i < n && j < m && s[i] == t[j]) {
            if (x == 0)
              comp(dp[i + 1][j + 1][cnt + 1][1], dp[i][j][cnt][x] + 1);
            else
              comp(dp[i + 1][j + 1][cnt][1], dp[i][j][cnt][x] + 1);
          }
        }
  int ans = 0;
  for (int i = 0; i <= k; i++)
    for (int j = 0; j < 2; j++) ans = max(ans, dp[n][m][i][j]);
  cout << ans << endl;
  if (0)
    cerr << fixed << setprecision(0)
         << "TIME = " << clock() / (long double)CLOCKS_PER_SEC * 1000 << "\n";
  return 0;
}
