#include <bits/stdc++.h>
using namespace std;
int a[200], b[200];
int n, m;
int num;
int main() {
  while (cin >> n) {
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (abs(a[i] - b[j]) <= 1) {
          b[j] = 10000;
          sum++;
          break;
        }
      }
    }
    printf("%d\n", sum);
  }
  return 0;
}
