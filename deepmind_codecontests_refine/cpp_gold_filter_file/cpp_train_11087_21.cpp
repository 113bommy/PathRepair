#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1];
  int b[n + 1];
  for (int i = 0; i < n; i++) cin >> a[i];
  int mx = INT_MIN;
  for (int i = n - 2; i >= 0; i--) {
    mx = max(mx, a[i + 1]);
    b[i] = mx;
  }
  for (int i = 0; i < n - 1; i++) {
    cout << max(b[i] - a[i] + 1, 0) << " ";
  }
  cout << 0 << endl;
  return 0;
}
