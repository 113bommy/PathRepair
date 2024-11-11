#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9;
const long long MOD = 1e9 + 7;
int inp[300100];
int get_bits(long long a) {
  int cnt = 0;
  while (a > 0) {
    if (a & 1) ++cnt;
    a >>= 1;
  }
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(20);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    inp[i] = get_bits(a);
  }
  int odd = 0, even = 1;
  int sum = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    sum += inp[i];
    if (sum & 1)
      ans += odd, odd++;
    else
      ans += even, even++;
  }
  for (int i = 0; i < n; i++) {
    int cur_sum = 0, mx = 0;
    for (int j = 0; j < 62 && j + i < n; j++) {
      cur_sum += inp[i + j];
      mx = max(mx, inp[i + j]);
      if (cur_sum & 1) continue;
      if (2 * mx <= cur_sum) continue;
      ans--;
    }
  }
  cout << ans << '\n';
  return 0;
}
