#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int k;
    cin >> k;
    long long int r = ceil(sqrt(k));
    long long int s = r * r;
    if (s == k) {
      cout << r << " " << 1 << "\n";
      continue;
    }
    int a = 2 * r;
    int d = s - k;
    if (d <= r) {
      cout << r << " " << d + 1 << "\n";
      continue;
    }
    long long int p = (r - 1) * (r - 1);
    cout << (k - p) << " " << r << "\n";
  }
  return 0;
}
