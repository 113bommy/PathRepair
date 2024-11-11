#include <bits/stdc++.h>
using namespace std;
int a[10000], b[10000];
int p[10000];
int i = 0;
int main() {
  int n = 0, m = 0, c = 0;
  cin >> n >> m >> c;
  while (cin >> p[i]) {
    if (p[i] <= c / 2) {
      for (int j = 0; j < n; j++) {
        if (a[j] == 0 || a[j] > p[i]) {
          a[j] = p[i];
          cout << j + 1 << endl;
          fflush(stdout);
          break;
        }
      }
    } else {
      for (int j = n - 1; j >= 0; j--) {
        if (a[j] == 0 || a[j] < p[i]) {
          a[j] = p[i];
          cout << j + 1 << endl;
          fflush(stdout);
          break;
        }
      }
    }
    i++;
  }
  return 0;
}
