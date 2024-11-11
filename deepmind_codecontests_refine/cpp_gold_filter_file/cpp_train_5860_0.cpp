#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int main() {
  long long fact[1010];
  fact[0] = 1;
  fact[1] = 1;
  for (int i = 2; i <= 1000; i++) fact[i] = (fact[i - 1] * i) % (mod);
  int n, x, pos;
  cin >> n >> x >> pos;
  vector<int> vl;
  int l = 0, r = n, m, small, big;
  small = x - 1;
  big = n - x;
  long long ans = 1;
  while (l < r) {
    m = (l + r) / 2;
    if (m < pos) {
      ans = (ans * small) % (mod);
      small--;
      l = m + 1;
    } else if (m > pos) {
      ans = (ans * big) % (mod);
      big--;
      r = m;
    } else if (m == pos)
      l = m + 1;
    ans = ans % mod;
  }
  ans = (ans * fact[n - (x - 1 - small) - (n - x - big) - 1]) % (mod);
  cout << ans % mod << endl;
}
