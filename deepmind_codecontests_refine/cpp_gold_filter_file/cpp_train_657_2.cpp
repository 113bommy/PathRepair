#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  gcd(b, a % b);
}
void sieve() {
  long long int i, j;
  long long int b[1000009];
  for (i = 2; i < 1000009; i++) {
    if (b[i] == 0) {
      for (j = 2 * i; j < 1000009; j = j + i) b[j] = 1;
    }
  }
}
long long int bs(pair<long long int, long long int> p[], long long int n,
                 long long int key, long long int i) {
  long long int low = i, high = n - 1;
  long long int ans = -1;
  while (low <= high) {
    long long int mid = low + high;
    mid = mid / 2;
    if (p[mid].first > key)
      high = mid - 1;
    else {
      low = mid + 1;
      ans = mid;
    }
  }
  return ans;
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int nCrModPFermat(long long int n, long long int r, long long int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  long long int fac[n + 1];
  fac[0] = 1;
  for (long long int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
struct piyush {
  long long int height;
  long long int index;
  piyush(long long int x, long long int y) {
    height = x;
    index = y;
  }
};
struct CompareHeight {
  bool operator()(piyush const& p1, piyush const& p2) {
    return p1.height > p2.height;
  }
};
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, i, j, k, t;
  cin >> n;
  string s[n];
  for (i = 0; i < n; i++) cin >> s[i];
  long long int ans = 0;
  for (i = 'a'; i <= 'z'; i++) {
    long long int hash[26];
    memset(hash, 0, sizeof(hash));
    for (j = 0; j < n; j++) {
      if (s[j][0] == i) {
        k = s[j].length();
        long long int lc = s[j][k - 1] - 'a';
        hash[lc] = max(hash[lc], hash[i - 'a'] + k);
      } else {
        k = s[j].length();
        long long int st = s[j][0] - 'a';
        if (hash[st] > 0) {
          long long int lc = s[j][k - 1] - 'a';
          hash[lc] = max(hash[lc], hash[st] + k);
        }
      }
    }
    ans = max(ans, hash[i - 'a']);
  }
  cout << ans << endl;
}
