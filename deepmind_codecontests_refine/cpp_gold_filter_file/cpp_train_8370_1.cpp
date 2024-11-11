#include <bits/stdc++.h>
const long long INF = 1000000000;
const double PI = 3.14159265358979323846;
const long long MOD = 1000000000 + 7;
using namespace std;
bool cmp(long long a, long long b) {
  if (a > b)
    return true;
  else
    return false;
}
long long f(long long n) {
  if (n % 2 == 1) {
    return n * (n - 1) / 2 + 1;
  } else {
    return n * n / 2;
  }
}
int main() {
  long long n, m;
  long long a[100005];
  cin >> n >> m;
  for (int i(0); i < m; i++) {
    int t;
    cin >> t >> a[i];
  }
  sort(a, a + m, cmp);
  long long l = 0, r = 1000000000;
  while (l + 1 != r) {
    long long mid = l + (r - l) / 2;
    if (f(mid) <= n)
      l = mid;
    else
      r = mid;
  }
  l = min(l, min(n, m));
  long long sum = 0;
  for (int i(0); i < l; i++) {
    sum += a[i];
  }
  cout << sum;
}
