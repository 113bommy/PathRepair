#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
vector<long long> ps;
long long n, k;
long long searchK(long long key) {
  long long L = n / 2 + 1;
  long long R = n;
  long long res = L;
  while (L <= R) {
    long long mid = (L + R) / 2;
    if (a[mid] < key) {
      res = mid;
      L = mid + 1;
    } else {
      R = mid - 1;
    }
  }
  return res;
}
bool check(long long ans, long long k) {
  long long ind = searchK(ans);
  return (ans * (ind - n / 2) - ps[n] + ps[n / 2] <= k);
}
long long searchAns(long long k) {
  long long L = a[n / 2 + 1];
  long long R = 2000000000;
  long long res = L;
  while (L <= R) {
    long long mid = (L + R) / 2;
    if (check(mid, k)) {
      res = mid;
      L = mid + 1;
    } else {
      R = mid - 1;
    }
  }
  return res;
}
int main() {
  cin >> n >> k;
  ps.assign(n + 1, 0);
  a.assign(n + 1, 0);
  for (long long i = 1; i <= n; i++) cin >> a[i];
  a[0] = -2000000000;
  sort(a.begin(), a.end());
  for (long long i = 1; i <= n; i++) ps[i] = ps[i - 1] + a[i];
  cout << searchAns(k);
  return 0;
}
