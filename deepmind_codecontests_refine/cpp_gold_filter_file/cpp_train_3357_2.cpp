#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    if (n > k) {
      cout << k << "\n";
      continue;
    }
    if (n == k) {
      cout << k + 1 << "\n";
      continue;
    }
    long long int x = k / (n - 1);
    if (k % (n - 1) != 0) x++;
    long long int z = (x - 1) * (n - 1);
    long long int y = x * n + 1 - n;
    while (z < k - 1) {
      y++;
      z++;
    }
    cout << y << "\n";
  }
  return 0;
}
