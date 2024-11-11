#include <bits/stdc++.h>
using namespace std;
long long base[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
string romCh[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                  "XL", "X",  "IX", "V",  "IV", "I"};
string roman(long long n) {
  string ans = "";
  for (int i = 0; i < 13; i++)
    if (n >= base[i]) ans += romCh[i], n -= base[i];
  return ans;
}
int main() {
  long long n = 0LL;
  long long a;
  string b;
  cin >> a >> b;
  n = 0LL;
  for (char c; cin >> c;) {
    int x = isdigit(c) ? c - 48 : c - 55;
    n = n * a + (long long)x;
  }
  if (b[0] == 'R') {
    cout << roman(n) << endl;
    return 0;
  }
  int ans[100], tot = 0, v = atoi(b.c_str());
  while (n) {
    ans[++tot] = n % (long long)v;
    n /= (long long)v;
  }
  for (int i = tot; i; i--)
    if (ans[i] >= 10)
      cout << char(55 + ans[i]);
    else
      cout << ans[i];
  if (!tot) cout << 0;
  cout << endl;
  return 0;
}
