#include <bits/stdc++.h>
using namespace std;
int n, a[1005], b[1005], p[1005];
bool check[1005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == b[i] && !check[a[i]]) {
      check[a[i]] = true;
      p[i] = a[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (p[i] == 0) {
      if (!check[a[i]]) {
        p[i] = a[i];
        check[a[i]] = true;
      } else {
        if (!check[b[i]]) {
          p[i] = b[i];
          check[b[i]] = true;
        } else {
          for (int j = 1; j <= n; j++) {
            if (!check[j]) {
              p[i] = j;
              check[j] = true;
              break;
            }
          }
        }
      }
    }
  }
  int posL = -1;
  for (int i = 1; i <= n; i++)
    if (a[i] != b[i]) {
      posL = i;
      break;
    }
  int posR = -1;
  for (int i = n; i > 0; i--)
    if (a[i] != b[i]) {
      posL = i;
      break;
    }
  if ((a[posL] != p[posL] && a[posR] != p[posR]) ||
      (b[posL] != p[posL] && b[posR] != p[posR])) {
    swap(p[posL], p[posR]);
  }
  for (int i = 1; i <= n; i++) {
    cout << p[i] << " ";
  }
  return 0;
}
