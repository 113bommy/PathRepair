#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
long long n, k, a[N], R[N], counter, x;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> x, a[x]++;
  for (int i = N - 1; i >= 1; i--) {
    counter += a[i];
    a[i / 2] += a[i] + R[i];
    R[i / 2 + i % 2] += a[i] + R[i];
    if (counter >= k) return cout << i, 0;
  }
  cout << -1;
  return 0;
}
