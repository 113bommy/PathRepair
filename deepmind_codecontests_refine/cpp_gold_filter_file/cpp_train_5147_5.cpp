#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (k * 2 >= n) {
    cout << "-1\n";
    return 0;
  }
  cout << n * k << "\n";
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= i + k; ++j) {
      cout << i << " " << (j <= n ? j : j - n) << "\n";
    }
  }
  return 0;
}
