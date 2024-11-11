#include <bits/stdc++.h>
using namespace std;
long long a[1000030];
template <typename T, typename U>
T max(T x, U y) {
  return x > y ? x : y;
}
template <typename T, typename U>
T min(T x, U y) {
  return x < y ? x : y;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    long long d;
    cin >> d;
    a[d]++;
  }
  for (int i = 0; i < 1000030; ++i) {
    a[i + 1] += a[i] / 2;
    ans += a[i] % 2;
  }
  cout << ans;
}
