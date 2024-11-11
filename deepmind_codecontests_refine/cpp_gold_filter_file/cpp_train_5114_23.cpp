#include <bits/stdc++.h>
using namespace std;
int f[105], a[105];
int n;
void nhap() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
}
void xl() {
  f[0] = 0;
  a[0] = 1;
  for (int i = 1; i <= n; ++i)
    if (a[i] == 1)
      f[i] = f[i - 1];
    else {
      if (a[i - 1] != 1 || a[i + 1] != 1)
        f[i] = f[i - 1];
      else {
        int dem = 0;
        for (int j = i - 1; j >= 0; --j) {
          if (a[j] == 1) ++dem;
          if (dem == 2) {
            f[i] = f[j] + 1;
            break;
          }
        }
      }
    }
  cout << f[n];
}
int main() {
  nhap();
  xl();
  return 0;
}
