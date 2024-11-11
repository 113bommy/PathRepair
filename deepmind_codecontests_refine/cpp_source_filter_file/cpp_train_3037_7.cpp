#include <bits/stdc++.h>
long long mod = 1000000007;
long long mod2 = 998244353;
long long OO = 1e18;
using namespace std;
long long n, m;
long long a[100100];
long long res[100100][20];
pair<long long, long long> help[100100][20];
long long david_villa(long long n) {
  if (n == 0) return 1;
  long long u = david_villa(n / 2);
  u = u * u;
  if (n % 2 == 1) u = u * 2;
  return u;
}
int main() {
  long long i, j;
  ;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    help[i][0].first = a[i];
    help[i][0].second = a[i];
  }
  for (i = 1; i <= n; i++) res[i][0] = 0;
  for (i = 1; i <= log2(n); i++) {
    long long indx = david_villa(i - 1);
    for (j = 1; j <= n; j++) {
      if (indx * 2 + j <= n) {
        help[j][i].first =
            (help[j][i - 1].first + help[j + indx][i - 1].first) % 10;
        help[j][i].second =
            (help[j][i - 1].first + help[j + indx][i - 1].first);
      }
    }
  }
  for (i = 1; i <= log2(n); i++) {
    long long indx = david_villa(i - 1);
    for (j = 1; j <= n; j++) {
      if (indx * 2 + j <= n) {
        res[j][i] = res[j][i - 1] + res[j + indx][i - 1];
        if (help[j][i].second >= 10) res[j][i]++;
      }
    }
  }
  cin >> m;
  while (m--) {
    long long st, en;
    cin >> st >> en;
    long long indx = log2(en - st + 1);
    cout << res[st][indx] << endl;
  }
  return 0;
}
