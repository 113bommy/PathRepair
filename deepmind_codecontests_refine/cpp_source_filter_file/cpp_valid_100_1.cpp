#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
long long fact[N];
const int MOD = 998244353;
long long power(long long x, long long y) {
  long long res = 1;
  x = x % MOD;
  while (y > 0) {
    if (y & 1) res = (res * x) % MOD;
    y = y >> 1;
    x = (x * x) % MOD;
  }
  return res;
}
long long modInverse(long long x) { return power(x, MOD - 2); }
long long modAdd(long long a, long long b) {
  return (a % MOD + b % MOD + 2 * MOD) % MOD;
}
long long modMult(long long a, long long b) {
  return (a % MOD * b % MOD) % MOD;
}
long long modDiv(long long a, long long b) {
  return (a % MOD * modInverse(b)) % MOD;
}
void getFact() {
  fact[0] = 1;
  for (auto i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
}
long long nCrModP(long long n, long long r) {
  if (r == 0) return 1;
  return ((fact[n] * modInverse(fact[r])) % MOD * modInverse(fact[n - r])) %
         MOD;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test;
  cin >> test;
  getFact();
  for (int t = 1; t <= test; t++) {
    int n;
    cin >> n;
    vector<long long> a(n);
    map<long long, int> m;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      m[a[i]]++;
    }
    sort(a.begin(), a.end());
    long long maxi = a[n - 1];
    int ind = n - 1;
    while (ind >= 0) {
      if (maxi == a[ind]) {
        ind--;
        continue;
      }
      if (maxi - a[ind] >= 2)
        maxi = -1;
      else
        maxi = a[ind];
      break;
    }
    if (maxi == -1 && m[a[n - 1]] > 1) {
      cout << "0\n";
      continue;
    }
    int cnt2 = m[maxi];
    int cnt1 = m[a[n - 1]];
    if (cnt1 > 1) {
      cout << fact[n] << "\n";
      continue;
    }
    int rem = n - cnt1 - cnt2;
    long long tot = fact[n];
    long long fs = fact[n - cnt1];
    fs = 0ll - fs;
    tot = modAdd(tot, fs);
    for (int i = 1; i <= rem; i++) {
      long long num = nCrModP(rem, i);
      long long rest = fact[n - 1 - i];
      long long no = fact[i];
      num = modMult(num, rest);
      no = modMult(no, num);
      no = 0ll - no;
      tot = modAdd(tot, no);
    }
    cout << tot << "\n";
  }
  return 0;
}
