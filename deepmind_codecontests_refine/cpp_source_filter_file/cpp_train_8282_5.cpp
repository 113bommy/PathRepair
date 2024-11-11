#include <bits/stdc++.h>
using namespace std;
long long met[555][55];
int main() {
  long long n, m, k;
  cin >> n >> m;
  string s;
  for (long long i = 0; i < n; i++) {
    cin >> s;
    met[i][1] = -1;
    met[i][2] = -1;
    met[i][3] = -1;
    for (long long j1 = 0; j1 <= n / 2; j1++) {
      long long j2 = n - j1;
      if (!j1) j2 = 0;
      if (met[i][1] == -1 &&
          ((s[j1] >= 'a' && s[j1] <= 'z') || (s[j2] >= 'a' && s[j2] <= 'z')))
        met[i][1] = j1;
      if (met[i][2] == -1 &&
          ((s[j1] >= '0' && s[j1] <= '9') || (s[j2] >= '0' && s[j2] <= '9')))
        met[i][2] = j1;
      if (met[i][3] == -1 && ((s[j1] == '&' || s[j1] == '#' || s[j1] == '*') ||
                              (s[j2] == '&' || s[j2] == '*' || s[j2] == '#')))
        met[i][3] = j1;
    }
  }
  long long ans = 2000000000;
  for (long long a1 = 0; a1 < n; a1++)
    for (long long a2 = 0; a2 < n; a2++)
      if (a1 != a2)
        for (long long a3 = 0; a3 < n; a3++)
          if (a2 != a3 && a1 != a3 && met[a1][1] != -1 && met[a2][2] != -1 &&
              met[a3][3] != -1)
            ans = min(ans, met[a1][1] + met[a2][2] + met[a3][3]);
  cout << ans;
  return 0;
}
