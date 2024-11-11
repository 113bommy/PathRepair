#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  string s;
  cin >> s;
  long long cnt = 0;
  for (long long i = 0; i < n - 1; i++) {
    if (s[i] != s[i + 1]) cnt++;
  }
  char dir[n];
  dir[n - 1 - cnt] = s[0];
  for (long long i = n - 2 - cnt; i >= 0; i--) {
    if (dir[i + 1] == 'L')
      dir[i] = 'R';
    else
      dir[i] = 'L';
  }
  for (long long i = n - cnt; i < n; i++) {
    if (dir[i - 1] == 'L')
      dir[i] = 'R';
    else
      dir[i] = 'L';
  }
  long long l = n - 1 - cnt, r = n - 1 - cnt;
  cout << a[n - 1 - cnt] << ' ' << dir[n - 1 - cnt] << '\n';
  for (long long i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) {
      l--;
      cout << a[l] << ' ' << dir[l] << '\n';
    } else {
      r++;
      cout << a[r] << ' ' << dir[r] << '\n';
    }
  }
}
