#include <bits/stdc++.h>
using namespace std;
long long mult(long long a, long long b, long long p = 1000000007) {
  return ((a % p) * (b % p)) % p;
}
long long add(long long a, long long b, long long p = 1000000007) {
  return (a % p + b % p) % p;
}
long long sub(long long a, long long b, long long p = 1000000007) {
  return (a % p - b % p + p) % p;
}
long long fpow(long long n, long long k, long long p = 1000000007) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
long long inv(long long a, long long p = 1000000007) {
  return fpow(a, p - 2, p);
}
int main() {
  int n;
  cin >> n;
  long long a[n];
  long long ans = 0;
  map<long long, long long> make_pair;
  set<long long> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    make_pair[a[i]]++;
    s.insert(a[i]);
  }
  sort(a, a + n);
  int i = 0, j = 1;
  for (; j < n; j++)
    if (a[j] != a[i]) {
      break;
    }
  for (int i = 0; i < n && j < n; i++) {
    if (a[i] < a[j]) {
      j++;
      ans++;
    } else {
      while (j < n && a[i] == a[j]) j++;
      if (j < n && a[i] < a[j]) {
        ans++;
        j++;
      }
    }
  }
  cout << ans;
}
