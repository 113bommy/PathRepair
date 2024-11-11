#include <bits/stdc++.h>
using namespace std;
long long fact[200001];
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2) {
      res = (res * a) % 998244353;
    }
    a = (a * a) % 998244353;
    b = b / 2;
  }
  return res;
}
long long solve(long long n, long long r) {
  if (r == 0) {
    return 1;
  }
  if (r > n) {
    return 1;
  }
  long long nfact = fact[n];
  long long nr = power(fact[n - r], 998244353 - 2);
  long long r1 = power(fact[r], 998244353 - 2);
  long long ans = nfact;
  ans = (ans * nr) % 998244353;
  ans = (ans * r1) % 998244353;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fact[0] = 1;
  fact[1] = 1;
  for (long long i = 2; i <= 200000; i++) {
    fact[i] = (i * fact[i - 1]) % 998244353;
  }
  int tc = 1;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    if (a[n - 1] - a[n - 2] > 1) {
      cout << "0"
           << "\n";
      continue;
    }
    if (a[n - 1] == a[n - 2]) {
      cout << fact[n] << "\n";
    } else {
      long long temp = 0;
      long long ct = 0;
      int el = a[n - 2];
      int i = n - 2;
      while (i >= 0 && a[i] == el) {
        i--;
        ct++;
      }
      for (int k = n; k > ct; k--) {
        long long elb = k - 1;
        long long ela = n - k;
        if (elb == n - 1) {
          temp += fact[n - 1];
        } else {
          long long nel = n - 1 - ct;
          long long plb = elb - ct;
          long long k1 = solve(nel, plb);
          long long toad = (k1 * fact[elb]) % 998244353;
          toad = (toad * fact[ela]) % 998244353;
          temp = (temp + toad) % 998244353;
        }
      }
      cout << (fact[n] - temp + 998244353) % 998244353 << "\n";
    }
  }
  return 0;
}
