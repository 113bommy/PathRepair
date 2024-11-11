#include <bits/stdc++.h>
using namespace std;
long long powm(long long base, long long exp, long long mod = 1000000007) {
  long long ans = 1;
  while (exp) {
    if (exp & 1) ans = (ans * base) % mod;
    exp >>= 1, base = (base * base) % mod;
  }
  return ans;
}
long long ctl(char x, char an = 'a') { return (long long)(x - an); }
char ltc(long long x, char an = 'a') { return (char)(x + an); }
long long a[1000005];
int main() {
  long long n;
  cin >> n;
  for (long long i = 1; i < n + 1; i++) cin >> a[i];
  if (n <= 2) {
    cout << 0;
    return 0;
  }
  long long minm = 1000111000111000111LL;
  for (long long diff1 = -1; diff1 < 2; diff1++)
    for (long long diff2 = -1; diff2 < 2; diff2++) {
      long long st = a[1] + diff1, diff = (a[2] + diff2) - (a[1] + diff1),
                prv = a[2] + diff2;
      long long tot = (diff1 != 0) + (diff2 != 0);
      for (long long i = 3; i < n + 1; i++) {
        long long curr = prv + diff;
        if (a[i] == curr)
          prv = a[i];
        else if (a[i] + 1 == curr)
          prv = a[i] + 1, tot++;
        else if (a[i] - 1 == curr)
          prv = a[i] - 1, tot++;
        else {
          tot = 1000111000111000111LL;
          break;
        }
      }
      minm = min(minm, tot);
    }
  cout << (minm >= n ? -1 : minm);
  return 0;
}
