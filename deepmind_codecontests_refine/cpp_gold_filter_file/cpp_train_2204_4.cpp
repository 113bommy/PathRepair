#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int lcm(int a, int b) { return abs(a * b) / gcd(a, b); }
const int inf = 1e8 + 1 - 1;
const int mod = inf + 7;
const int N = 1e5 + 500;
int n, m;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    char a[n][m];
    int ans = INT_MAX;
    int row[n];
    int col[m];
    for (int i = 0; i < n; i++) row[i] = 0;
    for (int i = 0; i < m; i++) col[i] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        if (a[i][j] == '.') {
          row[i]++;
          col[j]++;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int res = row[i] + col[j];
        if (a[i][j] == '.') res--;
        ans = min(ans, res);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
