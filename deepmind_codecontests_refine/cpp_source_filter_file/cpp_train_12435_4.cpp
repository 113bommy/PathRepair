#include <bits/stdc++.h>
using namespace std;
string s;
long long way[60][10];
long long ans = 0ll;
long long getWays(int pos, int dig) {
  if (pos == s.size()) return 1;
  if (!way[pos][dig]) {
    int tmp = dig + s[pos + 1] - '0';
    if (tmp % 2 == 1) way[pos][dig] += getWays(pos + 1, tmp / 2 + 1);
    way[pos][dig] += getWays(pos + 1, tmp / 2);
  }
  return way[pos][dig];
}
int main() {
  cin >> s;
  for (int i = 0; i < 10; i++) ans += getWays(0, i);
  int dig = s[0] - '0', i;
  for (i = 1; i < s.size(); i++)
    if (abs(s[i] - '0' - dig) <= 1)
      dig = s[i] - '0';
    else
      break;
  if (i == s.size())
    cout << ans - 1 << endl;
  else
    cout << ans + 1 << endl;
}
