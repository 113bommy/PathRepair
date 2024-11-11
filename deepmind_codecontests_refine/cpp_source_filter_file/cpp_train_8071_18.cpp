#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, cnt = 0, ans = 1;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (isdigit(s[i]))
      x = s[i] - '0';
    else if (s[i] >= 'A' && s[i] <= 'Z')
      x = s[i] - 'A' + 10;
    else if (isalpha(s[i]))
      x = s[i] - 'a' + 36;
    else if (s[i] == '-')
      s[i] = 62;
    else
      s[i] = 63;
    int bits = 0;
    while (x != 0) {
      bits++;
      if (x % 2 == 0) cnt++;
      x /= 2;
    }
    cnt += 6 - bits;
  }
  for (int i = 0; i < cnt; i++) {
    ans *= 3;
    ans %= 1000000007;
  }
  cout << ans << endl;
  return 0;
}
