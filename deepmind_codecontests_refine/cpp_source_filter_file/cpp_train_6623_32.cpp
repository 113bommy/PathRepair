#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, x;
  cin >> n >> k >> x;
  int a[n], sum = 2 * x;
  for (size_t i = 0; i < n; i++) cin >> a[i];
  for (size_t i = 0; i < n - k; i++) sum += a[i];
  cout << sum;
}
