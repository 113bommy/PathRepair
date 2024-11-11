#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000010;
const int p = 1000000007;
char s[MAXN];
int t[MAXN], n, cnt, ans;
int main() {
  cin >> s;
  n = strlen(s);
  cnt = 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a')
      cnt = cnt * 2 % p;
    else
      ans += (cnt - 1) % p;
  }
  cout << ans << endl;
  return 0;
}
