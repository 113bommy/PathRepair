#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m = 0;
  cin >> n;
  int ar[n];
  for (int i = 0; i < n; i++) cin >> ar[i];
  for (int i = 0; i < n - 1; i++) {
    if (ar[i] != ar[n - 1]) {
      m = max(m, n - i - 1);
      break;
    }
  }
  for (int i = n - 1; i >= 1; i--) {
    if (ar[i] != ar[0]) {
      m = max(m, i);
      break;
    }
  }
  cout << m;
  return 0;
}
