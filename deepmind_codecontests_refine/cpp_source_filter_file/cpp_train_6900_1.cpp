#include <bits/stdc++.h>
using namespace std;
long long fac(long long n) {
  long long p = 1;
  for (long long i = n; i > 0; i--) {
    p *= i;
  }
  return p;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long test_case = 1;
  while (test_case--) {
    string s;
    cin >> s;
    char minus = '-';
    char dot = '.';
    long long len = s.length();
    long long doti = -1;
    for (int i = 0; i < len; i++) {
      if (s[i] == '.') {
        doti = i;
        break;
      }
    }
    long long cnt = 0;
    string ans;
    if (doti >= 0) {
      for (int i = doti - 1; i >= 0; i--) {
        if (s[i] == '-') continue;
        cnt++;
        if ((cnt - 1) % 3 == 0 && cnt != 1) {
          ans = ans + ',';
        }
        ans = ans + s[i];
      }
      reverse(ans.begin(), ans.end());
      if (len - doti >= 3) {
        ans = ans + '.' + s[doti + 1] + s[doti + 2];
      } else if (len - doti == 2) {
        long long ok = doti + 1;
        ans = ans + '.' + s[ok] + '0';
      } else if (len - doti == 1) {
        ans = ans + '.' + '0' + '0';
      }
    }
    if (doti < 0) {
      for (int i = len - 1; i >= 0; i--) {
        if (s[i] == '-') continue;
        cnt++;
        if ((cnt - 1) % 3 == 0 && cnt != 1) {
          ans = ans + ',';
        }
        ans = ans + s[i];
      }
      reverse(ans.begin(), ans.end());
      ans = ans + '.' + '0' + '0';
    }
    if (s[0] == '-') {
      cout << "("
           << "&" << ans << ")"
           << "\n";
    }
    if (s[0] != '-') {
      cout << "&" << ans << "\n";
    }
  }
}
