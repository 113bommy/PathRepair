#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, x;
  cin >> n >> x;
  vector<long long> a(n * 2);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  n *= 2;
  vector<long long> B = {0};
  vector<long long> C = {0};
  for (long long i = 0; i < n; i++) {
    B.push_back(B.back() + a[i]);
    C.push_back(C.back() + (a[i] * (a[i] + 1)) / 2);
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    if (B[i + 1] >= x) {
      long long z = upper_bound(B.begin(), B.end(), B[i + 1] - x) - B.begin();
      long long days = B[i + 1] - B[z];
      long long cnt = C[i + 1] - C[z];
      long long too = x - days;
      cnt += ((a[z - 1] * (a[z - 1] + 1)) / 2);
      cnt -= (((a[z - 1] - too) * (a[z - 1] - too + 1)) / 2);
      ans = max(ans, cnt);
    }
  }
  cout << ans << "\n";
  return 0;
}
