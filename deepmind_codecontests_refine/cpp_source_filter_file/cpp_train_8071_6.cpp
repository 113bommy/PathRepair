#include <bits/stdc++.h>
using namespace std;
int conv(char a) {
  if (a >= '0' && a <= '9') {
    return a - '0';
  } else if (a >= 'A' && a <= 'Z') {
    return a - 'A' + 10;
  } else if (a >= 'a' && a <= 'z') {
    return a - 'a' + 36;
  }
  if (a == '-') return 62;
  return 63;
}
int main() {
  string s;
  cin >> s;
  int tows = 0;
  int mx = 0;
  long long ans1 = 1;
  for (int i = 0; i < s.size(); i++) {
    mx = max(mx, conv(s[i]));
  }
  for (int i = 0; i < s.size(); i++) {
    tows = 0;
    long long ans = 1;
    int k = conv(s[i]);
    int co = 1;
    int it = 0;
    while (mx >= co) {
      if ((k >> it) % 2 == 0) tows++;
      it++;
      co *= 2;
    }
    for (int i = 0; i < tows; i++) {
      ans *= 3;
      ans %= 1000000007;
    }
    ans1 = ans1 % 1000000007 * ans % 1000000007;
    ans1 %= 1000000007;
  }
  ans1 %= 1000000007;
  cout << ans1 << endl;
}
