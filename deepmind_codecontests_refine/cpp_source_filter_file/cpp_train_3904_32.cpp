#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k == 0) {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    if (a < 5 || a > n - 4 || b < 5 || b > m - 4) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
