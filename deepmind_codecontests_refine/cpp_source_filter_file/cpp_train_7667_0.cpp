#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b, long long int m) {
  if (b == 0) return (1);
  long long int sol = power(a, b / 2, m);
  sol = (sol * sol) % m;
  if (b % 2 == 1) sol = (sol * a) % m;
  return (sol);
}
string s[1005];
int has[1001][256];
int countt[1001];
void solve() {
  int n, ans = 0, cc = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    int j = s[i].length();
    for (int k = 0; k < j; k++) {
      has[i][s[i][k]] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (countt[i] == 0) {
      countt[i] = 1;
      ans++;
      for (int j = 0; j < n; j++) {
        cc = 0;
        if (countt[j] == 0) {
          for (int k = 0; k < 120; k++) {
            if (has[i][k] == has[j][k]) {
              cc++;
            }
          }
          if (cc == 120) countt[j] = 1;
        }
      }
    }
  }
  cout << ans;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
