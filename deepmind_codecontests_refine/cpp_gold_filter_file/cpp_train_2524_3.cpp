#include <bits/stdc++.h>
using namespace std;
int a, b;
int x(int* a, int* b) {
  if (*a < 2 || *b < 1)
    return 1;
  else {
    *a -= 2;
    *b--;
    return 0;
  }
}
int y(int* a, int* b) {
  if (*a < 1 || *b < 2)
    return 1;
  else {
    *a -= 1;
    *b -= 2;
    return 0;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, f = -1, l = 0, w = 0;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] % x) {
        if (f == -1) f = i;
        l = i;
      }
      w += a[i];
    }
    if (w % x)
      cout << n;
    else if (f == -1)
      cout << -1;
    else
      cout << max(n - f - 1, l);
    cout << endl;
  }
  return 0;
}
