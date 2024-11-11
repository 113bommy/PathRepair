#include <bits/stdc++.h>
using namespace std;
long long Seive[200006];
long long searchgreater(vector<long long> &v, long long target) {
  long long l = 0, u = (long long)v.size() - 1;
  long long m;
  while (l <= u) {
    m = (l + u) / 2;
    if (v[m] < target) {
      l = m + 1;
    } else {
      if (v[m] > target) {
        u = m - 1;
      } else {
        u = m - 1;
      }
    }
  }
  if (v[l] >= target)
    return l;
  else
    return v.size();
}
long long searchlower(vector<long long> &array, long long start_idx,
                      long long end_idx, long long search_val) {
  if (start_idx == end_idx)
    return array[start_idx] <= search_val ? start_idx : -1;
  long long mid_idx = start_idx + (end_idx - start_idx) / 2;
  if (search_val < array[mid_idx])
    return searchlower(array, start_idx, mid_idx, search_val);
  long long ret = searchlower(array, mid_idx + 1, end_idx, search_val);
  return ret == -1 ? mid_idx : ret;
}
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return ((a * b) / gcd(a, b)); }
long long binpow(long long a, long long b, long long m) {
  if (b == 0) {
    return 1;
  }
  if (b == 1) {
    return a;
  }
  if (b % 2 == 0) {
    long long temp = binpow(a, b / 2, m);
    return (temp % m * temp % m) % m;
  } else {
    long long temp = binpow(a, (b - 1) / 2, m);
    return (temp % m * temp % m * a % m) % m;
  }
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInverse(long long n, long long p) { return power(n, p - 2, p); }
long long fact[200006];
void factorial(long long p) {
  fact[0] = 1;
  fact[1] = 1;
  for (long long i = 2; i < 200006; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] = fact[i] % p;
  }
}
long long nCrModPFermat(long long n, long long r, long long p) {
  if (n < r) {
    return 0;
  }
  if (r == n) {
    return 1;
  }
  return (fact[n] * modInverse(fact[r], p) % p * modInverse(fact[n - r], p) %
          p) %
         p;
}
void PrimeSeive() {
  long long N = 200006;
  long long i;
  for (i = 2; i < N; i++) {
    Seive[i] = 1;
  }
  Seive[0] = 0;
  Seive[1] = 0;
  long long j;
  for (i = 2; i * i < N; i++) {
    if (Seive[i] == 1) {
      for (j = i * i; j < N; j += i) Seive[j] = 0;
    }
  }
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
long long mod1(long long a, long long b) {
  long long c = a % b;
  if (c < 0) {
    return c + b;
  } else
    return c;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  long long mxm = INT_MIN;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    mxm = max(mxm, a[i]);
  }
  long long curr_max;
  long long cnt = 0;
  for (long long i = n - 1; i >= 0; i--) {
    if (i == n - 1) {
      if (a[i] == mxm) {
        cout << 0 << "\n";
        return;
      } else {
        curr_max = 0;
      }
    } else {
      if (a[i] > curr_max && a[i] == mxm) {
        cnt++;
        curr_max = a[i];
        cout << cnt << "\n";
        return;
      } else if (a[i] > curr_max) {
        cnt++;
        curr_max = a[i];
      }
    }
  }
  cout << cnt << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  PrimeSeive();
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
