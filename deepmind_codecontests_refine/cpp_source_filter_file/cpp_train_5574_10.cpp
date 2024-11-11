#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (m == 0) {
    cout << 1 << endl;
    return 0;
  }
  int min2 = INT_MAX, max1 = 0;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    min2 = min(min2, max(a, b));
    max1 = max(max1, min(a, b));
  }
  cout << max(0, min2 - max1) << endl;
}
