#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  t = 1;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long i;
    long long one = 0;
    string ans = "";
    for (i = 0; i < n; i++) {
      if (s[i] == '0') {
        ans += '0';
      } else
        one++;
    }
    if (one >= 1) ans = '1' + ans;
    cout << ans << endl;
  }
}
