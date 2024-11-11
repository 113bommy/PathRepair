#include <bits/stdc++.h>
using namespace std;
int num[2005];
bool mk[2005];
int n;
long long comb[2005];
long long fact[2005];
long long mod = 1e9 + 7;
long long exp(long long a, int pow) {
  if (pow == 1) return a;
  if (pow == 0) return 1;
  long long res = exp(a, pow / 2);
  res = (res * res) % mod;
  if (pow % 2 == 1) res = (res * a) % mod;
  return res;
}
void fac() {
  fact[1] = fact[0] = 1;
  for (int i = 2; i <= n; i++) {
    fact[i] = ((long long)fact[i - 1] * (long long)i) % mod;
  }
}
void cnk(int v) {
  comb[0] = 1;
  comb[1] = v;
  for (int i = 2; i <= n; i++) {
    long long a = ((long long)fact[v] * (long long)exp(fact[i], mod - 2)) % mod;
    long long b = (exp(fact[v - i], mod - 2));
    comb[i] = ((long long)a * (long long)b) % mod;
  }
}
int main() {
  cin >> n;
  int total = 0;
  int fixed = 0;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    if (num[i] != -1)
      mk[num[i]] = true;
    else
      total++;
  }
  for (int i = 1; i <= n; i++) {
    if (num[i] == -1 && !mk[i]) fixed++;
  }
  fac();
  cnk(fixed);
  long long res = fact[total];
  for (int i = 1; i <= fixed; i++) {
    if (i == 1) {
      res = (res - ((long long)fact[total - 1] * (long long)fixed) % mod +
             (long long)mod) %
            mod;
    } else {
      if (i % 2 == 0)
        res = (res + ((long long)comb[i] * (long long)fact[total - i]) % mod) %
              mod;
      else
        res = (res - ((long long)comb[i] * (long long)fact[total - i]) % mod +
               (long long)mod) %
              mod;
    }
  }
  cout << res << endl;
  return 0;
}
