#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int x, long long int y) {
  if (x < y) swap(x, y);
  if (x % y == 0) return y;
  return gcd(y, x % y);
}
long long int pwm(long long int a, long long int n) {
  long long int ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans = (ans * a) % 1000000007;
    }
    a = (a * a) % 1000000007;
    n /= 2;
  }
  return ans % 1000000007;
}
const int pwn = 100010;
long long int pw[pwn];
void pwtwo() {
  pw[0] = 1;
  for (int i = 1; i < pwn; i++) {
    pw[i] = (pw[i - 1] * 2) % 1000000007;
  }
}
long long int gcdExtended(long long int a, long long int b, long long int *x,
                          long long int *y);
long long int modInverse(long long int a, long long int m) {
  if (a == 1) return 1;
  long long int x, y;
  long long int g = gcdExtended(a, m, &x, &y);
  if (g != 1) {
    return -1;
  } else {
    long long int res = (x % m + m) % m;
    return res;
  }
}
long long int gcdExtended(long long int a, long long int b, long long int *x,
                          long long int *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long int x1, y1;
  long long int gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long int fact[1010];
long long int init() {
  fact[0] = 1;
  for (int i = 1; i < 1010; i++) fact[i] = (fact[i - 1] * i) % 1000000007;
}
long long int ncr(long long int n, long long int r) {
  long long int ans = fact[n];
  ans = (ans * modInverse(fact[r], 1000000007)) % 1000000007;
  ans = (ans * modInverse(fact[n - r], 1000000007)) % 1000000007;
  return ans;
}
long long int zstr[20][4];
string nines[20];
long long int nstr[20][4];
bool chkPerf(string &x, int i) {
  if (i == x.size()) return true;
  if (i >= x.size() || x[i++] != '1') return false;
  while (i < x.size()) {
    if (x[i++] != '0') return false;
  }
  return true;
}
bool chkNine(string &x, int i) {
  while (i < x.size()) {
    if (x[i++] != '9') return false;
  }
  return true;
}
long long int classy(string &x, int i, int z) {
  if (z < 0) return 0;
  if (chkPerf(x, i) && zstr[x.size() - i][z] != -1)
    return zstr[x.size() - i][z];
  if (chkNine(x, i) && zstr[x.size() - i][z] != -1) {
    return nstr[x.size() - i][z];
  }
  if (i == x.size()) {
    if (z == 0)
      return 1;
    else
      return 0;
  }
  if (x[i] == '0') {
    return classy(x, i + 1, z);
  }
  long long int ans = classy(x, i + 1, z - 1);
  ans += ((long long int)(x[i] - '0') - 1) *
         classy(nines[x.size() - i - 1], 0, z - 1);
  ans += classy(nines[x.size() - i - 1], 0, z);
  if (chkNine(x, i)) {
    nstr[x.size() - i][z] = ans;
    ;
  }
  return ans;
}
void initClassy() {
  string nine = "";
  for (int i = 0; i < 20; i++) {
    nines[i] = nine;
    nine += "9";
  }
  memset(zstr, -1, sizeof(zstr));
  memset(nstr, -1, sizeof(nstr));
  zstr[0][0] = 1;
  zstr[0][1] = 0;
  zstr[0][2] = 0;
  zstr[0][3] = 0;
  string str = "1";
  for (int i = 1; i < 20; i++) {
    for (int j = 0; j < 4; j++) {
      zstr[i][j] = classy(str, 0, j);
    }
    str += '0';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m, i, j, ans, l, r, t;
  string s;
  cin >> t;
  initClassy();
  while (t--) {
    cin >> l >> r;
    string lx = to_string(l - 1);
    string rx = to_string(r);
    cout << (classy(rx, 0, 3) + classy(rx, 0, 2) + classy(rx, 0, 1) +
             classy(rx, 0, 0)) -
                (classy(lx, 0, 3) + classy(lx, 0, 2) + classy(lx, 0, 1) +
                 classy(lx, 0, 0))
         << endl;
  }
  return 0;
}
