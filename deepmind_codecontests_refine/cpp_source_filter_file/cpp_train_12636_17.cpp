#include <bits/stdc++.h>
using namespace std;
int a[2000010];
int main() {
  int n;
  while (cin >> n) {
    int begin = 0;
    for (int i = 0; i < n; ++i) {
      a[i] = i + 1;
    }
    for (int i = 2; i <= n; ++i) {
      for (int p = n / i * i; p >= 0; p -= i) {
        a[min(n - 1, p + i) + begin] = a[p + begin];
      }
      ++begin;
    }
    for (int i = 0; i < n; ++i) {
      printf("%d ", a[i + begin]);
    }
    cout << endl;
  }
  return 0;
}
