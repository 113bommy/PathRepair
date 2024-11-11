#include <bits/stdc++.h>
using namespace std;
long long int n, k;
bool pdt(long long int x) {
  long long int sum = x;
  long long int d = k;
  while (x > 0) {
    if (floor(x / d) == 0) break;
    sum += floor(x / d);
    d = d * k;
  }
  if (sum >= n) return true;
  return false;
}
void solve() {
  long long int a, b;
  cin >> n >> a >> b;
  long long int v[n];
  for (long long int i = 0; i < n; i++) cin >> v[i];
  sort(v, v + n);
  cout << abs(v[b] - v[b - 1]) << "\n";
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
