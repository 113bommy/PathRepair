#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
template <typename T>
inline T Abs(T a) {
  return a < 0 ? -a : a;
}
int n, k, a[N];
int main() {
  scanf("%d %d", &n, &k);
  for (int i = (int)1; i <= (int)n - 1; ++i) a[i] = 1;
  a[n] = 0;
  for (int i = (int)1; i <= (int)k; ++i) {
    for (int j = (int)1; j <= (int)n; ++j) {
      if (a[j] == n - j)
        cout << n << " ";
      else if (a[j] * 2 <= n - i - 1) {
        a[j] *= 2;
        cout << j << " ";
      } else {
        int toadd = abs((n - j) - a[j]);
        cout << (n - toadd) << " ";
        a[j] = n - j;
      }
    }
    puts("");
  }
}
