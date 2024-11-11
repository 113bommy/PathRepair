#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-7;
int a[100004];
int r[100004];
int n;
bool u[20][20];
int main() {
  memset(u, false, sizeof(u));
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    int p = a[i];
    for (int j = 0; j < 20; ++j) {
      if (p & (1 << j)) {
        for (int k = 0; k < 20; ++k) {
          if (!(p & (1 << k))) {
            u[j][k] = true;
          }
        }
      }
    }
  }
  int nn = 0;
  for (int i = 20 - 1; i >= 0; --i) {
    bool b = true;
    for (int j = 0; j < i; ++j) {
      if (!u[i][j]) {
        b = false;
        break;
      }
    }
    if (b) {
      for (int k = 0; k < n; ++k) {
        if (a[k] & (1 << i)) {
          r[nn++] = a[k];
        }
      }
      printf("%d\n", nn);
      for (int k = 0; k < nn; ++k) {
        printf("%d ", r[k]);
      }
      return 0;
    }
  }
  return 0;
}
