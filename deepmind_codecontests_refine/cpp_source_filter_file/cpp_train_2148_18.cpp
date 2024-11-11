#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m = 0, a[200001], b[200001] = {0}, k = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[n - i - 1];
    if (a[n - i - 1] > m) m = a[n - i - 1];
  }
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      b[a[i]] = -1;
      continue;
    }
    if (b[a[i]] != 0) continue;
    b[a[i]] = i;
  }
  k = *max_element(b + 1, b + m + 1);
  if (k == -1) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i <= m; i++)
    if (b[i] == k) {
      cout << i;
      return 0;
    }
}
