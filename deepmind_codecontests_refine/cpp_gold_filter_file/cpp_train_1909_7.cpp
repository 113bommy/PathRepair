#include <bits/stdc++.h>
using namespace std;
long long sm[5007][5007];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  string s, t;
  cin >> s >> t;
  long long i, j, k;
  long long n = s.length();
  long long m = t.length();
  s = '$' + s;
  t = '$' + t;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      sm[i][j] =
          (sm[i][j - 1] + (s[i] == t[j]) * (sm[i - 1][j - 1] + 1)) % 1000000007;
    }
  }
  long long smm = 0;
  for (i = 1; i <= n; i++) {
    smm = (smm + sm[i][m]) % 1000000007;
  }
  cout << smm;
}
