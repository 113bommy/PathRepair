#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t = 1;
  while (t--) {
    long long int n, sum = 0, ans = 0, ct = 0, m, l, r, k, d;
    cin >> n;
    string s;
    cin >> s;
    string a = "";
    for (long long int i = 0; i < n; i++) {
      if (s[i] == '1' || s[i] == '0') continue;
      if (s[i] == '2' || s[i] == '3') {
        a += s[i];
        continue;
      }
      if (s[i] == '4') a += "223";
      if (s[i] == '9') a += "3327";
      if (s[i] == '7' || s[i] == '5') a += s[i];
      if (s[i] == '6') a += "35";
      if (s[i] == '8') a += "2227";
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    cout << a << '\n';
  }
  return 0;
}
