#include <bits/stdc++.h>
using namespace std;
long long a[64], t, ans = 1, modulo = 1e9 + 7;
string s;
int main() {
  for (int i = 0; i < 64; i++) {
    a[i] = 1;
    t = i;
    for (int j = 0; j < 6; j++) {
      if ((t % 2) == 0) a[i] *= 3;
      t / 2;
    }
  }
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] >= '0' && s[i] <= '9') ans *= a[int(s[i] - '0')];
    if (s[i] >= 'a' && s[i] <= 'z') ans *= a[int(s[i] - 'a' + 36)];
    if (s[i] >= 'A' && s[i] <= 'Z') ans *= a[int(s[i] - 'A' + 10)];
    if (s[i] == '-') ans *= a[62];
    if (s[i] == '_') ans *= a[63];
    ans %= modulo;
  }
  cout << ans;
}
