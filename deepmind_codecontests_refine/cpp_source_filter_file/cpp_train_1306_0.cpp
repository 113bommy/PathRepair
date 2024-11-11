#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > tt;
string s, s1, s2, s3;
char a[1001][1001];
long long kl, n, m, i, j, k, b[1001][1001], a1, b1, c1, c2, sc[1001], sc1[1001];
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == '*') {
        sc[i]++;
        sc1[j]++;
        kl++;
      }
    }
  for (i = 1; i <= n; i++) {
    long long dp = sc[i];
    for (j = 1; j <= n; j++) {
      long long dp1 = dp + sc1[j];
      if (a[i][j] == '*') dp1--;
      if (dp1 == kl) {
        cout << "YES"
             << "\n";
        cout << i << " " << j << "\n";
        return 0;
      }
    }
  }
  cout << "NO"
       << "\n";
  return 0;
}
