#include <bits/stdc++.h>
using namespace std;
const int MX = (int)1e6 + 17;
const int MOD = (int)1e9 + 7;
const long long oo = (long long)1e18 + 7;
const int INF = (int)999999999;
const int N = (int)1e5 + 17;
inline long long IN() {
  long long x = 0, ch = getchar(), f = 1;
  while (!isdigit(ch) && (ch != '-') && (ch != EOF)) ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void OUT(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10)
    OUT(x / 10), putchar(x % 10 + '0');
  else
    putchar(x + '0');
}
int n;
void get(int x, int y) {
  string ans;
  while (x--) ans += '4';
  while (y--) ans += '7';
  cout << ans;
  exit(0);
}
int main() {
  cin >> n;
  for (int i = 0; i < (int)3e5; i++) {
    for (int j = 0; j < (int)3e5; j++) {
      if (j * 4 + i * 7 == n) get(j, i);
      if (j * 4 + i * 7 > n) break;
    }
  }
  cout << -1;
  return 0;
}
