#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int n, k;
vector<int> an;
int f[2][5] = {{0, 1, 2, 0, 1}, {0, 1, 0, 1, 2}};
int canWin(int x) {
  if (x < 5) return f[k % 2][x];
  if (k % 2 == 0) {
    if (x % 2)
      return 0;
    else
      return 1;
  }
  if (x % 2)
    return 0;
  else
    return canWin(x / 2) == 1 ? 2 : 1;
}
int main() {
  cin >> n >> k;
  an.resize(n);
  for (int i = 0; i < (int)n; i++) cin >> an[i];
  int ret = 0;
  for (int i = 0; i < (int)n; i++) {
    int t = canWin(an[i]);
    ret ^= t;
  }
  if (ret)
    cout << "Kevin" << endl;
  else
    cout << "Nicky" << endl;
  return 0;
}
