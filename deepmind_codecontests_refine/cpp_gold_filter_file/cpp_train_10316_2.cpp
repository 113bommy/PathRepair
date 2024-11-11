#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  string s, t;
  long long cnt = 0;
  cin >> s >> t;
  for (int i = 0; i < n / 2; i++) {
    if (t[i] == t[n - 1 - i]) {
      if (s[i] == s[n - 1 - i]) {
      } else {
        if (t[i] == s[i] || t[i] == s[n - 1 - i])
          cnt++;
        else
          cnt++;
      }
    } else {
      if (t[i] == s[i] && t[n - 1 - i] == s[n - 1 - i]) {
      } else if (t[i] == s[i])
        cnt++;
      else if (t[n - 1 - i] == s[n - 1 - i])
        cnt++;
      else if (s[i] == t[n - 1 - i] && s[n - 1 - i] == t[i]) {
      } else if (s[i] == t[n - 1 - i])
        cnt++;
      else if (s[n - 1 - i] == t[i])
        cnt++;
      else
        cnt += 2;
    }
  }
  if (n % 2 == 1)
    if (s[n / 2] != t[n / 2]) cnt++;
  cout << cnt;
}
