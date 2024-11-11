#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int a[105];
  while (cin >> n >> k) {
    int t1 = k % n;
    int t2 = k / n;
    int num = 1;
    for (int i = 0; i < n; i++) a[i] = t2;
    for (int i = 0; i < t1; i++) a[i]++;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < i + n; j++) {
        cout << a[(j % n)];
        if (j != i + n - 1) cout << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}
