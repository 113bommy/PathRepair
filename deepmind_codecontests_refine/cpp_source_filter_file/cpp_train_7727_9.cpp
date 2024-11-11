#include <bits/stdc++.h>
using namespace std;
long long m = 1000000007;
long long *fact;
long long powr(long long x, long long y, long long modulo = m) {
  if (y % 2 == 0) {
    return 1;
  }
  long long mul = powr(x, y / 2, modulo);
  long long prod = (mul * mul) % modulo;
  if (y & 1) {
    prod = (prod * x) % modulo;
  }
  return prod;
}
struct compare {
  bool operator()(const pair<long long, long long> &a,
                  const pair<long long, long long> &b) {
    return a.first < b.first;
  }
  bool operator()(const long long &a, const pair<long long, long long> &b) {
    return a < b.first;
  }
  bool operator()(const pair<long long, long long> &a, const long long &b) {
    return a.first < b;
  }
};
long long *create1D(long long n, long long initial = 0) {
  long long *arr = new long long[n];
  for (long long i = 0; i < n; i++) {
    arr[i] = initial;
  }
  return arr;
}
long long **create2D(long long n, long long m, long long initial = 0) {
  long long **arr = new long long *[n];
  for (long long i = 0; i < n; i++) {
    arr[i] = new long long[m];
    for (long long j = 0; j < m; j++) {
      arr[i][j] = initial;
    }
  }
  return arr;
}
long long ***create3D(long long n, long long m, long long k,
                      long long initial = 0) {
  long long ***arr = new long long **[n];
  for (long long i = 0; i < n; i++) {
    arr[i] = new long long *[m];
    for (long long j = 0; j < m; j++) {
      arr[i][j] = new long long[k];
      for (long long l = 0; l < k; l++) {
        arr[i][j][l] = initial;
      }
    }
  }
  return arr;
}
void fill_fact(long long end, long long modulo = m) {
  fact = new long long[end + 1];
  fact[0] = 1;
  for (long long i = 1; i <= end; i++) {
    fact[i] = (fact[i - 1] * i) % modulo;
  }
  return;
}
long long combinations(long long n, long long r) {
  if (n < r) return 1;
  long long prod = (fact[n] / ((fact[r] * fact[n - r])));
  return prod;
}
int32_t main() {
  m = 998244353;
  long long T = 1;
  while (T--) {
    long long N;
    cin >> N;
    for (long long length = 1; length <= N; length++) {
      long long ans = 0;
      long long total = N - length + 1;
      long long left_out_elements = N - length - 1;
      long long f = 1;
      if (left_out_elements > 0) {
        f = powr(10, left_out_elements, m);
      }
      if (length != N) {
        ans = (f * (10 * 9)) % m;
        ans = (2 * ans) % m;
      } else {
        ans = (10) % m;
      }
      left_out_elements = N - length - 2;
      long long subarrays = N - length + 1 - 2;
      f = 1;
      if (left_out_elements >= 0 && subarrays > 0) {
        ans = (ans + ((subarrays * 9 * 10 * 9) % m) *
                         (powr(10, left_out_elements, m))) %
              m;
      }
      cout << ans << " ";
    }
  }
}
