#include <bits/stdc++.h>
using namespace std;
const long long int p = 31;
const long long int MOD = 1e9 + 9;
long long int t;
string s;
long long int fpw[1000001];
long long int bpw[1000001];
long long int fsh[1000001];
long long int bsh[1000001];
long long int ix1, ix2;
long long int mx;
long long int fast_exp(long long int base, long long int expz) {
  long long int res = 1;
  while (expz > 0) {
    if (expz % 2 == 1) res = (res * base) % MOD;
    base = (base * base) % MOD;
    expz /= 2;
  }
  return res % MOD;
}
void solve() {
  cin >> s;
  long long int ln = 0;
  for (int i = 0; s[i]; i++) {
    fsh[i] = (s[i] - 'a' + 1) * fpw[i];
    fsh[i] %= MOD;
    if (i != 0) fsh[i] += fsh[i - 1];
    fsh[i] %= MOD;
  }
  for (int i = s.length() - 1; i >= 0; i--) {
    bsh[i] = (s[i] - 'a' + 1) * bpw[i];
    bsh[i] %= MOD;
    if (i != s.length() - 1) bsh[i] += bsh[i + 1];
    bsh[i] %= MOD;
  }
  long long int l = 0;
  long long int r = s.length() - 1;
  while (l < r && s[l] == s[r]) {
    ln++;
    l++;
    r--;
  }
  mx = 0;
  ix1 = ix2 = -1;
  long long int lhash;
  long long int rhash;
  for (int i = l; i <= r; i++) {
    lhash = fsh[i];
    if (l - 1 >= 0) lhash -= fsh[l - 1];
    if (lhash < 0) lhash += MOD;
    lhash = (lhash * fast_exp(fpw[l], MOD - 2)) % MOD;
    rhash = bsh[l];
    if (i + 1 < s.length()) rhash -= bsh[i + 1];
    if (rhash < 0) rhash += MOD;
    rhash = (rhash * fast_exp(bpw[i], MOD - 2)) % MOD;
    if (lhash == rhash) {
      long long int tmp = i - l + 1;
      if (tmp > mx) {
        mx = tmp;
        ix1 = l;
        ix2 = i;
      }
    }
    lhash = fsh[r];
    if (i - 1 >= 0) lhash -= fsh[i - 1];
    if (lhash < 0) lhash += MOD;
    lhash = (lhash * fast_exp(fpw[i], MOD - 2)) % MOD;
    rhash = bsh[i];
    if (r + 1 < s.length()) rhash -= bsh[r + 1];
    if (rhash < 0) rhash += MOD;
    rhash = (rhash * fast_exp(bpw[r], MOD - 2)) % MOD;
    if (lhash == rhash) {
      long long int tmp = r - i + 1;
      if (tmp > mx) {
        mx = tmp;
        ix1 = i;
        ix2 = r;
      }
    }
  }
  for (int i = 0; i < ln; i++) cout << s[i];
  if (ix1 != -1) {
    for (int i = ix1; i <= ix2; i++) cout << s[i];
  }
  for (int i = s.length() - ln; i < s.length(); i++) cout << s[i];
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  fpw[0] = 1;
  for (int i = 1; i < 1000001; i++) fpw[i] = (p * fpw[i - 1]) % MOD;
  bpw[1000000] = 1;
  for (int i = 1000000 - 1; i >= 0; i--) bpw[i] = (p * bpw[i + 1]) % MOD;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
