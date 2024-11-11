#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, sum = 0, ans = 0, mn = INT_MAX;
  cin >> n;
  string s;
  cin >> s;
  long long int ps[n], m[n];
  for (i = 0; i < n; i++) {
    if (s[i] == ')') sum--;
    if (s[i] == '(') sum++;
    ps[i] = sum;
  }
  for (i = n - 1; i >= 0; i--) {
    mn = min(mn, ps[i]);
    m[i] = mn;
  }
  if (sum != 2 && sum != -2) goto A;
  for (i = 0; i < n; i++)
    if (ps[i] < -2) goto A;
  if (sum == 2) {
    for (i = 0; i < n; i++) {
      if (ps[i] < 0) goto A;
      ;
      if (s[i] == '(' && m[i] > 1) ans++;
    }
  }
  if (sum == -2) {
    for (i = 0; i < n - 1; i++) {
      if (s[i] == ')' && m[i] > -1) ans++;
      if (ps[i] < 0) goto A;
    }
  }
A:
  cout << ans;
  return 0;
}
