#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int d = a[1] - a[0];
  for (int i = 1; i < n; i++) {
    if (a[i + 1] - a[i] != d) {
      cout << a[n - 1];
      return 0;
    }
  }
  cout << a[n - 1] + d;
  return 0;
}
