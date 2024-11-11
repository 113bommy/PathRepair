#include <bits/stdc++.h>
using namespace std;
long long n, l, x, y;
long long a[100100];
int main() {
  cin >> n >> l >> x >> y;
  for (int i = 0; i < n; i++) cin >> a[i];
  bool fx = false, fy = false;
  for (int i = 0; i < n; i++) {
    if (binary_search(a, a + n, a[i] + x)) {
      fx = true;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (binary_search(a, a + n, a[i] + y)) {
      fy = true;
      break;
    }
  }
  if (fx && fy) {
    printf("0\n");
    return 0;
  }
  if (fx && !fy) {
    printf("1\n");
    cout << y << endl;
    return 0;
  }
  if (!fx && fy) {
    printf("1\n");
    cout << x << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (binary_search(a, a + n, a[i] + x + y)) {
      printf("1\n");
      cout << a[i] + x << endl;
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (binary_search(a, a + n, a[i] + y - x)) {
      if (a[i] + y > l && a[i] - x < 0) continue;
      if (a[i] + y > l) {
        printf("1\n");
        cout << a[i] + y << endl;
      } else {
        printf("1\n");
        cout << a[i] - x << endl;
      }
      return 0;
    }
  }
  printf("2\n");
  cout << x << ' ' << y << endl;
  return 0;
}
