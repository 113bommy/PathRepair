#include <bits/stdc++.h>
using namespace std;
long long PO[10000009], MOD = 1000003, MODM = 1000002;
int main() {
  long long i, j, k, l, n, m, ans, tot, sum, temp, now, din, num, inda, tt, ind;
  PO[0] = 1;
  for (i = 1; i <= 10000000; i++) {
    PO[i] = PO[i - 1] * 2;
    PO[i] %= MOD;
  }
  cin >> n >> k;
  if (n < 62) {
    now = 1LL << n;
    if (k > now) {
      cout << "1 1\n";
      return 0;
    }
  }
  temp = n % MODM;
  temp *= (k % MODM);
  temp %= MODM;
  temp -= n;
  temp %= MODM;
  temp += MODM;
  temp %= MODM;
  tot = k - 1;
  now = 2;
  while (tot / now) {
    temp -= tot / now;
    now *= 2;
    temp %= MODM;
    temp += MODM;
    temp %= MODM;
  }
  din = PO[temp];
  if (k - 1 >= MOD) {
    num = din;
  } else {
    num = din;
    ans = 1;
    for (i = 1; i <= k - 1; i++) {
      ind = i;
      tt = 0;
      while (ind % 2 == 0) {
        tt++;
        ind /= 2;
      }
      ind = n % MODM;
      ind -= tt;
      ind %= MODM;
      ind += MODM;
      ind %= MODM;
      inda = i;
      inda /= (1LL << tt);
      now = PO[ind] - inda;
      now %= MOD;
      now += MOD;
      now %= MOD;
      ans *= now;
      ans %= MOD;
    }
    num -= ans;
    num %= MOD;
    num += MOD;
    num %= MOD;
  }
  cout << num << " " << din << endl;
}
