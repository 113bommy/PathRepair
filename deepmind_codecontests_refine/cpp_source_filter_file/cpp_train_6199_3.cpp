#include <bits/stdc++.h>
using namespace std;
int a[1100], b[1100];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i(1); i <= n; ++i) cin >> b[i];
  for (int i(k); i > 0; --i) a[i] = n - i + 1;
  for (int i(n - k); i > 0; --i) {
    int tmp(b[i]);
    int j(n - i);
    for (j; tmp; --j) {
      if (a[j] > i) --tmp;
      a[j + 1] = a[j];
    }
    a[j + 1] = i;
  }
  for (int i(n); i > 0; --i) {
    cout << a[i];
    if (i == 1)
      cout << endl;
    else
      cout << " ";
  }
  return 0;
}
