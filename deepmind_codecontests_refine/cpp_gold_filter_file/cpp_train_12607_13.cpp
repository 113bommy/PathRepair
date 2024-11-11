#include <bits/stdc++.h>
using namespace std;
long long n, t, a[200001], b[200001], x[200001];
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  cin >> n >> t;
  for (long long i = 1; i <= n; i++) cin >> a[i], b[i] = a[i] + t;
  long long ma = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> x[i];
    if (x[i] < x[i - 1] || x[i] < i) cout << "No\n", exit(0);
    ma = max(ma, x[i]);
    if (ma > i) b[i] = b[i + 1], ++b[i + 1];
  }
  long long L = 1, R = 1;
  while (L <= n) {
    R = max(R, L + 1);
    while (R <= n && a[R] + t <= b[R - 1]) ++R;
    if (x[L] != R - 1) cout << "No\n", exit(0);
    ++L;
  }
  cout << "Yes\n";
  for (long long i = 1; i <= n; i++) cout << b[i] << (i == n ? '\n' : ' ');
  return 0;
}
