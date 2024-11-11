#include <bits/stdc++.h>
using namespace std;
void qq(int n) {
  int i, j, ans = 0, mod = 5, base[10];
  base[1] = base[2] = base[3] = base[4] = 1;
  for (i = 1; i <= n; i++)
    for (j = 2; j <= 4; j++) {
      base[j] *= j;
      base[j] %= mod;
    }
  for (i = 1; i <= 4; i++) ans += base[i];
  ans %= mod;
  cout << n << ' ' << ans << endl;
}
int main() {
  int i, a, sz;
  string s;
  cin >> s;
  sz = s.size();
  a = s[sz - 1] - '0';
  if (sz > 1) a = a + (s[sz - 2] - '0') * 10;
  a %= 4;
  if (a == 0) cout << "4" << endl;
  if (a == 1 || a == 3) cout << "0" << endl;
  if (a == 2) cout << "0" << endl;
}
