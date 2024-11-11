#include <bits/stdc++.h>
using namespace std;
long long min(long long a, long long b) {
  if (a > b) return b;
  return a;
}
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long next_prime(long long a) {
  long long flag;
  for (long long i = a + 1;; i++) {
    flag = 0;
    for (long long j = 2; j <= sqrt(i); j++) {
      if (i % j == 0) {
        flag = 1;
        break;
      }
    }
    if (!flag) return i;
  }
}
int32_t main() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> v;
  for (long long i = 1; i <= n; i++) {
    if (i != n)
      v.push_back(pair<long long, long long>(i, i + 1));
    else
      v.push_back(pair<long long, long long>(n, 1));
  }
  long long a = next_prime(n);
  for (long long i = 1; i <= (a - n); i++) {
    v.push_back(pair<long long, long long>(i, n - i));
  }
  cout << v.size() << endl;
  for (auto x : v) {
    cout << x.first << " " << x.second << endl;
  }
  return 0;
}
