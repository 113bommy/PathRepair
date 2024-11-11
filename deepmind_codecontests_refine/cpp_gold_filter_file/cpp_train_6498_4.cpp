#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
int main() {
  string s;
  long long ans = 0;
  cin >> s;
  long long cnt = 0;
  int n = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'b' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'r' &&
        i + 3 < s.size())
      ans += (cnt + 3) * (cnt + 4) / 2, i += 3, cnt = 3, n++, ans -= 3;
    else
      cnt++, n++;
  }
  ans += cnt * (cnt + 1) / 2;
  cout << s.size() * (s.size() + 1) / 2 - ans;
  return 0;
}
