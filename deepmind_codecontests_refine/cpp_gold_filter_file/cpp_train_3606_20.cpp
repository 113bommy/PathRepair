#include <bits/stdc++.h>
using namespace std;
bool checksq(int k) {
  for (int i = 0; i <= sqrt(k); i++) {
    if (i * i == k) {
      return true;
    }
  }
  return false;
}
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = n - 1; i >= 0; i--) {
    if (checksq(a[i]) == 0) {
      cout << a[i];
      break;
    }
  }
  return 0;
}
