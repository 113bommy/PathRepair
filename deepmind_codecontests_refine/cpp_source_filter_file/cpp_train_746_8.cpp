#include <bits/stdc++.h>
using namespace std;
long long __gcd(long long a, long long b) {
  if (b == 0) return a;
  return __gcd(b, a % b);
}
void solve() {
  long long n, k;
  cin >> n >> k;
  if (k < (n * (n + 1)) / 2) {
    cout << -1 << '\n';
    return;
  }
  int cnt[n + 1];
  for (int i = 1; i < n + 1; i++) cnt[i] = i;
  int mm = n - 1;
  int K = k;
  k = k - (n * (n + 1)) / 2;
  for (int i = n; i > n / 2 + (n % 2); i--) {
    if (k > mm) {
      k = k - mm;
      swap(cnt[i], cnt[i - mm]);
      mm = mm - 2;
    } else {
      swap(cnt[i], cnt[i - k]);
      k = 0;
      break;
    }
  }
  cout << K - k << '\n';
  for (int i = 1; i < n + 1; i++) cout << cnt[i] << " ";
  cout << '\n';
  for (int i = 1; i < n + 1; i++) cout << i << " ";
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
