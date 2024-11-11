#include <bits/stdc++.h>
using namespace std;
long long minimum(long long a[], long long n) {
  long long mn = INT_MAX, i;
  for (i = 1; i <= n; i++) mn = min(mn, a[i]);
  return mn;
}
long long maximum(long long a[], long long n) {
  long long mx = INT_MIN, i;
  for (i = 1; i <= n; i++) mx = max(mx, a[i]);
  return mx;
}
int main() {
  int i, j, cnt = 0;
  int a[30] = {0};
  string s;
  cin >> s;
  for (i = 0; s[i]; i++) a[s[i] - 'a']++;
  if (a[8] == 0 || a[4] % 3 || a[19] == 0) {
    cout << 0;
    return 0;
  }
  cnt = min(a[8], min(a[4] / 3, a[19]));
  int mx = (a[13] & 1) ? (a[13] / 2) : (a[13] / 2 - 1);
  cout << min(mx, cnt);
  return 0;
}
