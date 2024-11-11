#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long a[n];
  long long ss = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    ss += a[i];
  }
  if (ss == 1) {
    cout << -1;
    return 0;
  }
  vector<long long> ff;
  for (long long i = 2; i * i <= ss; i++) {
    if (ss % i == 0) {
      ff.push_back(i);
    }
    while (ss % i == 0) {
      ss /= i;
    }
  }
  if (ss > 1) ff.push_back(ss);
  long long b[n];
  for (long long j = 0; j < n; j++) {
    b[j] = a[j];
  }
  for (long long j = 1; j < n; j++) b[j] += b[j - 1];
  long long an = 0, mi = 2000000000000000000;
  for (long long i = 0; i < ff.size(); i++) {
    long long p = ff[i];
    an = 0;
    for (long long j = 0; j < n; j++) {
      long long tt = min(b[j] % p, (p - b[j] % p));
      an += tt;
    }
    mi = min(mi, an);
  }
  cout << mi;
  return 0;
}
