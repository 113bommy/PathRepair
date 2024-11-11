#include <bits/stdc++.h>
using namespace std;
long long mult(long long a, long long b, long long p = (long long)(998244353)) {
  return ((a % p) * (b % p)) % p;
}
long long add(long long a, long long b, long long p = (long long)(998244353)) {
  return (a % p + b % p) % p;
}
long long fpow(long long n, long long k, long long p = (long long)(998244353)) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
long long inv(long long a, long long p = (long long)(998244353)) {
  return fpow(a, p - 2, p);
}
bool sa(const pair<long long, long long> &a,
        const pair<long long, long long> &b) {
  return (a.second < b.second);
}
bool fd(const pair<long long, long long> &a,
        const pair<long long, long long> &b) {
  return (a.first > b.first);
}
bool sd(const pair<long long, long long> &a,
        const pair<long long, long long> &b) {
  return (a.second > b.second);
}
long long dx[4] = {0, 0, 1, -1};
long long dy[4] = {1, -1, 0, 0};
bool valid(long long x, long long y, long long n, long long m) {
  if (x < 0 || y < 0) {
    return false;
  } else if (x >= n || y >= m) {
    return false;
  } else
    return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, val, val1, f = 0;
  cin >> n;
  long long a[n + 5], b[n + 5];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  val = 0;
  val1 = n - 1;
  for (long long i = 0; i < n; i++) {
    if (i % 2 == 0) {
      b[val] = a[i];
      val++;
    } else {
      b[val1] = a[i];
      val1--;
    }
  }
  for (long long i = 0; i < n; i++) {
    if (i == 0) {
      if (a[n - 1] + a[1] <= a[0]) {
        f = 1;
        break;
      }
    } else if (i == n - 1) {
      if (a[n - 2] + a[0] <= a[n - 1]) {
        f = 1;
        break;
      }
    } else {
      if (a[i - 1] + a[i + 1] <= a[i]) {
        f = 1;
        break;
      }
    }
  }
  if (f == 1) {
    cout << "NO";
    return 0;
  } else {
    cout << "YES\n";
  }
  for (long long i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  return 0;
}
