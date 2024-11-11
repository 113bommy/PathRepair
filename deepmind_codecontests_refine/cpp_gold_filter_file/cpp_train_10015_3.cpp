#include <bits/stdc++.h>
using namespace std;
const int vx[4] = {0, 1, 0, -1};
const int vy[4] = {1, 0, -1, 0};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  vector<char> v;
  for (char c = 'a'; c <= 'z'; c++) v.push_back(c);
  for (char c = 'A'; c <= 'Z'; c++) v.push_back(c);
  for (char c = '0'; c <= '9'; c++) v.push_back(c);
  long long t;
  cin >> t;
  while (t--) {
    long long y, x, k;
    cin >> y >> x >> k;
    char s[110][110];
    long long r = 0;
    for (long long i = (long long)0; i < (long long)y; i++) {
      cin >> s[i];
      for (long long j = (long long)0; j < (long long)x; j++)
        if (s[i][j] == 'R') r++;
    }
    char ans[110][110];
    long long i = 0, j = 0;
    long long sum = 0;
    long long c = 0;
    long long rk = r / k;
    long long rc = r % k;
    while (i < y) {
      while (j < x && j >= 0) {
        ans[i][j] = v[c];
        if (k > 0 && s[i][j] == 'R') {
          sum++;
          if (rc == 0 && sum == rk || sum > rk) {
            if (c < k - 1) c++;
            sum = 0;
            if (rc > 0) rc--;
          }
        }
        if (i % 2 == 0)
          j++;
        else
          j--;
      }
      if (j == x)
        j--;
      else
        j++;
      i++;
    }
    for (long long i = (long long)0; i < (long long)y; i++) {
      for (long long j = (long long)0; j < (long long)x; j++) {
        cout << ans[i][j];
      }
      cout << endl;
    }
  }
}
