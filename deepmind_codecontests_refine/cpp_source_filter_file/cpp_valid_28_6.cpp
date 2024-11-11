#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
using namespace std::chrono;
long long mul(long long a, long long b) { return (a * b) % 1000000007; }
long long modinv(long long a) {
  long long b = 1000000007 - 2;
  long long A = a;
  long long c = 1;
  for (long long i = 0; i < 62; i++) {
    if ((long long)1 << i & (b)) {
      c = mul(c, A);
    }
    A *= A;
    A %= 1000000007;
  }
  return c;
}
long long mul(long long a, long long b, long long c) {
  return mul(mul(a, b), c);
}
long long nCr(long long n, long long r) {
  long long num = 1;
  long long den = 1;
  long long k = max(r, n - r);
  for (long long i = k + 1; i <= n; i++) {
    num = mul(num, i);
  }
  for (long long i = 1; i <= n - k; i++) {
    den = mul(den, i);
  }
  return mul(num, modinv(den));
}
long long gcd(long long x, long long y) {
  if (y > x) {
    return gcd(y, x);
  } else if (y == 0) {
    return x;
  } else {
    return gcd(y, x % y);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long T;
  cin >> T;
  while (T--) {
    long long n, m;
    cin >> n >> m;
    vector<long long> A(n + 1, 0);
    vector<long long> pos(n + 1, 0);
    vector<long long> correct(n + 1, 0);
    for (long long i = 1; i < n + 1; i++) {
      cin >> A[i];
      pos[A[i]] = i;
    }
    map<long long, long long> mp;
    for (long long i = 1; i < n + 1; i++) {
      mp[A[i] - i]++;
    }
    vector<long long> ans;
    for (long long i = 0; i < n; i++) {
      long long total = mp[-1 * (i)];
      if (i > 0) {
        total += mp[(n - i)];
      }
      if (total >= (n - 2 * m)) {
        for (long long j = 1; j < i + 1; j++) {
          correct[j] = j + n - i;
        }
        for (long long j = i + 1; j < n + 1; j++) {
          correct[j] = j - i;
        }
        vector<bool> visited(n + 1, 0);
        total = 0;
        for (long long i = 1; i < n + 1; i++) {
          long long r = i;
          ;
          long long len = 0;
          if (visited[r] == 0) {
            visited[r] = 1;
            len++;
            r = pos[correct[r]];
          }
          if (len) {
            total += len - 1;
          }
        }
        if (total <= m) {
          ans.push_back(i);
        }
      }
    }
    cout << ans.size() << " ";
    for (long long i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
    ;
  }
  return 0;
}
