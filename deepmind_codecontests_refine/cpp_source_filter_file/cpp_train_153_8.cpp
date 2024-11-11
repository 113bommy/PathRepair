#include <bits/stdc++.h>
using namespace std;
long long n, i, a[3], j, x, c, ans;
string s;
int main() {
  c = 0;
  ans = 0;
  while (getline(cin, s)) {
    switch (s[0]) {
      case '+': {
        c++;
        break;
      }
      case '-': {
        c--;
        break;
      }
      default: {
        ans += c * (s.length() - s.find(':'));
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
