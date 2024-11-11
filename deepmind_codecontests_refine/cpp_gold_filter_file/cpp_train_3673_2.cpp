#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string s;
  while (t--) {
    long long n, i;
    cin >> n;
    cin >> s;
    long long pre[n], pre1[n], pre2[n], pre3[n];
    if (s[0] == '<')
      pre[0] = 1;
    else
      pre[0] = 0;
    for (i = 1; i < n; i++) {
      if (s[i] == '<')
        pre[i] = pre[i - 1] + 1;
      else
        pre[i] = pre[i - 1];
    }
    if (s[n - 1] == '<')
      pre1[n - 1] = 1;
    else
      pre1[n - 1] = 0;
    for (i = n - 2; i >= 0; i--) {
      if (s[i] == '<')
        pre1[i] = pre1[i + 1] + 1;
      else
        pre1[i] = pre1[i + 1];
    }
    if (s[0] == '>')
      pre2[0] = 1;
    else
      pre2[0] = 0;
    for (i = 1; i < n; i++) {
      if (s[i] == '>')
        pre2[i] = pre2[i - 1] + 1;
      else
        pre2[i] = pre2[i - 1];
    }
    if (s[n - 1] == '>')
      pre3[n - 1] = 1;
    else
      pre3[n - 1] = 0;
    for (i = n - 2; i >= 0; i--) {
      if (s[i] == '>')
        pre3[i] = pre3[i + 1] + 1;
      else
        pre3[i] = pre3[i + 1];
    }
    long long l, r, ans = 0;
    for (i = 0; i < n; i++) {
      r = (i + 1) % n;
      l = (i - 1 + n) % n;
      if (s[i] == '-')
        ans++;
      else if (s[i] == '<') {
        if (pre2[l] == 0 && pre3[r] == 0)
          ans++;
        else if (s[l] == '-')
          ans++;
      } else if (s[i] == '>') {
        if (pre[l] == 0 && pre1[r] == 0)
          ans++;
        else if (s[l] == '-')
          ans++;
      }
    }
    cout << ans << endl;
  }
}
