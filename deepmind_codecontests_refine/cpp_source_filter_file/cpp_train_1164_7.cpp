#include <bits/stdc++.h>
using namespace std;
long long n, m, k, y, a, b, c;
long long A[1005], B[1005], C[1005];
string s;
int main() {
  cin >> n >> k;
  cin >> s;
  s = '+' + s + '+';
  for (int i = 1; i <= n && k;) {
    if (s[i] == '4') {
      if (s[i - 1] == '4' && s[i + 1] == '7' && i % 2) {
        if (k % 1) s[i] = '7';
        break;
      }
    }
    if (s[i] == '4' && s[i + 1] == '7') {
      if (i % 2) {
        s[i + 1] = '4';
        i++;
      } else {
        s[i] = '7';
        i--;
      }
      k--;
    } else {
      i++;
    }
  }
  for (int i = int(1); i < int(n + 1); i++) {
    cout << s[i];
  }
}
