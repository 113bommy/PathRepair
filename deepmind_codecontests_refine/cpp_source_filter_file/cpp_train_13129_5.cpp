#include <bits/stdc++.h>
using namespace std;
using namespace std;
int inp;
void sc(long long &x) {
  scanf("%d", &inp);
  x = inp;
}
void sc(long long &x, long long &y) {
  scanf("%d", &inp);
  x = inp;
  scanf("%d", &inp);
  y = inp;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void setbit(int &m, int ind, int val) {
  if (val)
    m = (m | (1 << ind));
  else
    m = (m & ~(1 << ind));
}
bool getbit(int m, int ind) {
  int a = (1 << ind);
  a = (a & m);
  return a;
}
int cntbits(int m) {
  int ret = 0;
  while (m) {
    ret += (m % 2);
    m /= 2;
  }
  return ret;
}
bool smlltr(char c) {
  if (c >= 'a' && c <= 'z') return 1;
  return 0;
}
bool capltr(char c) {
  if (c >= 'A' && c <= 'Z') return 1;
  return 0;
}
const long long mod = 1e9 + 7;
const long long mod2 = 998244353;
const long long mod3 = 1e9 + 9;
long long pow_mod(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2) return (a * pow_mod((a * a) % mod, b / 2)) % mod;
  return pow_mod((a * a) % mod, b / 2);
}
int n, m, tmp, d, x, y, z, k, sol, maxi, mini, sum, T, k1, k2;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> x >> y >> d;
    tmp = abs(x - y);
    if (tmp % d == 0) {
      cout << tmp / d << endl;
      continue;
    }
    sol = 2147483645;
    k1 = (x - 1) / d;
    if ((x - 1) % d != 0) k1++;
    k2 = (n - x) / d;
    if ((n - x) % d != 0) k2++;
    if (y % d == 1) sol = (y / d) + k1;
    if ((n - y) % d == 0) sol = min(sol, (n - y) / d + k2);
    if (sol == 100000)
      cout << -1 << endl;
    else
      cout << sol << endl;
  }
  return 0;
}
