#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(2 * n);
  for (auto &x : a) cin >> x;
  sort(a.begin(), a.end());
  long long s1 = a[n - 1] - a[0];
  long long s2 = a[2 * n - 1] - a[n];
  long long minimo = s1 * s2;
  for (long long i = (1); i < (long long)(n); i++) {
    long long s1 = a[i + n - 1] - a[i];
    long long s2 = a[2 * n - 1] - a[0];
    minimo = min(minimo, s1 * s2);
  }
  printf("%lld\n", minimo);
}
