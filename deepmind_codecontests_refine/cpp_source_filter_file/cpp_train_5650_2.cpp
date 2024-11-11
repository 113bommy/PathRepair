#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int maxim = 0, sum = 0, a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      maxim = max(maxim, a[i]);
      sum += a[i];
    }
    if (maxim > sum / 2) {
      cout << "T\n";
      continue;
    }
    if (sum % 2 == 0)
      cout << "HT\n";
    else
      cout << "T\n";
  }
  return 0;
}
