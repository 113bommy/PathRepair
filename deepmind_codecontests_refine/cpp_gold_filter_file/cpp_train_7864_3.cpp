#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    if (n == 1 && a[n - 1] != 0 && a[n - 1] != 15) {
      cout << "-1";
      return 0;
    }
    if (n == 1 && a[n - 1] == 15) {
      cout << "DOWN";
      return 0;
    }
    if (n == 1 && a[n - 1] == 0) {
      cout << "UP";
      return 0;
    }
    if (a[n - 1] < a[n - 2] && a[n - 1] > 0) {
      cout << "DOWN";
      return 0;
    }
    if (a[n - 1] < a[n - 2] && a[n - 1] == 0) {
      cout << "UP";
      return 0;
    }
    if (a[n - 1] > a[n - 2] && a[n - 1] != 15) {
      cout << "UP";
      return 0;
    }
    if (a[n - 1] > a[n - 2] && a[n - 1] == 15) {
      cout << "DOWN";
      return 0;
    }
  }
  return 0;
}
