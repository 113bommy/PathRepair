#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, x, sum = 0;
  cin >> n >> x >> k;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - x; i++) sum += a[i];
  sum += k * x;
  cout << sum;
  return 0;
}
