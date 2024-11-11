#include <bits/stdc++.h>
using namespace std;
const double Pi = 2.0 * acos(0.0);
const double Ex = 2.7182818284;
const int Mod = 1e9 + 7;
const int oo = 2e9 + 1e8;
int di[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dj[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dik[] = {-1, -1, 1, 1, -2, -2, 2, 2};
int djk[] = {2, -2, 2, -2, 1, -1, 1, -1};
long long gcd(long long x, long long y) { return !y ? x : gcd(y, x % y); }
void getInt(int &ret) {
  char tmpc;
  bool sign = 0;
  while (tmpc = getchar()) {
    if (tmpc < '0' || tmpc > '9')
      sign = (tmpc == '-');
    else
      break;
  }
  ret = tmpc - '0';
  while (tmpc = getchar(), tmpc >= '0' && tmpc <= '9')
    ret = ret * 10 + tmpc - '0';
  if (sign) ret *= -1;
}
int main() {
  int n, ans = 0;
  int xa, xb, ya, yb;
  cin >> n;
  for (int i = 0; i < int(n); i++) {
    cin >> xa >> ya >> xb >> yb;
    for (int i = (int)1; i < (int)100; i++)
      for (int j = (int)1; j < (int)100; j++)
        if (i >= xa && i <= xb && j >= ya && j <= yb) ans++;
  }
  cout << ans << endl;
  return 0;
}
