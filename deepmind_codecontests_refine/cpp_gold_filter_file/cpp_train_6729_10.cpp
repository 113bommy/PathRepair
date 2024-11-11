#include <bits/stdc++.h>
using namespace std;
int n, a[100000 + 10];
inline int lg2(int x) { return sizeof(int) * 8 - __builtin_clz(x) - 1; }
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  if (n % 2) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    iota(a + 1, a + 100000 + 1, 1);
    int n0 = n;
    while (n) {
      int ref = 1 << lg2(n);
      int j = 0;
      for (j = 0; ref + j <= n; j++) swap(a[ref - j - 1], a[ref + j]);
      n = ref - j - 1;
    }
    n = n0;
    for (int i = 1; i <= n; i++) cout << a[i] << (i == n ? '\n' : ' ');
  }
  if (1 << lg2(n) == n || n < 6)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    if (n == 6)
      cout << "3 6 2 5 1 4" << endl;
    else {
      a[1] = 7, a[2] = 3, a[3] = 2, a[4] = 6, a[5] = 4, a[6] = 5, a[7] = 1;
      for (int i = 8; i <= n; i <<= 1) {
        for (int j = 0; j < min(n - i + 1, i); j++) a[i + j] = i + j + 1;
        a[min(n, i * 2 - 1)] = i;
      }
      for (int i = 1; i <= n; i++) cout << a[i] << (i == n ? '\n' : ' ');
    }
  }
  return 0;
}
