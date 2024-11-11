#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[105], d;
  cin >> n >> d;
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n == 1) {
    cout << "0" << endl;
    return 0;
  }
  sort(a, a + n);
  int p = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int s = 0;
      s = abs(a[i] - a[j]);
      if (s == d) {
        p = max(p, j - i + 1);
      }
    }
  }
  cout << n - p << endl;
}
