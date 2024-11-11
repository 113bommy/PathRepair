#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long n = s.length(), ans = 0, pre[n], suf[n];
  if (s[0] == 'Q')
    pre[0] = 1;
  else
    pre[0] = 0;
  if (s[n - 1] == 'Q')
    suf[n - 1] = 1;
  else
    suf[n - 1] = 0;
  for (long long i = 1; i < n; ++i) {
    if (s[i] == 'Q')
      pre[i] = pre[i - 1] + 1;
    else
      pre[i] = pre[i - 1];
  }
  for (long long i = n - 2; i >= 0; --i) {
    if (s[i] == 'Q')
      suf[i] = suf[i + 1] + 1;
    else
      suf[i] = suf[i + 1];
  }
  for (long long i = 0; i < n; ++i) {
    if (s[i] == 'A') ans += pre[i] * suf[i];
  }
  cout << ans << endl;
}
