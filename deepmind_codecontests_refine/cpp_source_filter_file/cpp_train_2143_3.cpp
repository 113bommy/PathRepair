#include <bits/stdc++.h>
using namespace std;
long long a[22222];
vector<long long> bm;
long long sum(long long x) {
  long long ret = x + 1;
  ret *= x;
  ret /= 2;
  return ret;
}
int main() {
  long long n, k;
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    a[x]++;
  }
  if (k == 0) {
    long long ans = 0;
    for (long long i = 1; i <= 10000; i++) {
      if (a[i]) ans += sum(a[i] - 1);
    }
    cout << ans;
    return 0;
  }
  long long mx = 16384;
  for (long long i = 0; i < mx; i++) {
    long long j = i;
    long long ke = 0;
    while (j) {
      ke += j % 2;
      j /= 2;
    }
    if (ke == k) bm.push_back(i);
  }
  long long m = 10000;
  long long ans = 0;
  for (long long i = 0; i <= m; i++) {
    if (a[i] == 0) continue;
    for (long long j = 0; j < bm.size(); j++) {
      ans += a[i] * a[i ^ bm[j]];
    }
  }
  cout << ans / 2;
  return 0;
}
