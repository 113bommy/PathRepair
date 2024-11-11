#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[1100];
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  while (a[0] != 0) {
    for (int i = 0; i < n; ++i) {
      if (i & 1)
        a[i] = (a[i] - 1) % n;
      else
        a[i] = (a[i] + 1) % n;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] != i) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
