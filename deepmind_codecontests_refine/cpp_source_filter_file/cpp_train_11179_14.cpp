#include <bits/stdc++.h>
using namespace std;
int a[20000];
int main() {
  int n, k;
  while (cin >> n >> k) {
    for (int i = 0; i < n; i++) a[i] = 1;
    a[n - 1] = 0;
    for (int i = 0; i < k; i++)
      for (int j = 0; j < n; j++) {
        int d = (n - j - 1) - a[j];
        int t = min(d, 1 << (i + 1));
        a[j] += t;
        cout << n - t;
        if (j == n - 1)
          cout << endl;
        else
          cout << ' ';
      }
  }
  return 0;
}
