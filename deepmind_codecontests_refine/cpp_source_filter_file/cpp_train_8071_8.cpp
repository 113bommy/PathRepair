#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int INF = 1e9 + 9;
const int MX = 1e5 + 5;
string s;
int inp[MX];
int cnt[65];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    int tmp;
    tmp = s[i];
    if (s[i] == '-')
      inp[i] = 62;
    else if (s[i] == '_')
      inp[i] = 63;
    else if (tmp >= 48 and tmp <= 57)
      inp[i] = inp[i] - 48;
    else if (tmp >= 65 and tmp <= 90)
      inp[i] = tmp - 65 + 10;
    else if (tmp >= 97 and tmp <= 122)
      inp[i] = tmp - 97 + 36;
  }
  for (int i = 0; i <= 63; i++)
    for (int j = 0; j <= 63; j++) cnt[i & j]++;
  long long ans = 1;
  for (int i = 0; i < s.size(); i++) ans = (ans * 1LL * cnt[inp[i]]) % MOD;
  cout << ans << endl;
  return 0;
}
