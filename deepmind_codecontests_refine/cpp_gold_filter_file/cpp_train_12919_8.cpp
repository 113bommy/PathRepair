#include <bits/stdc++.h>
using namespace std;
const int debug = 1;
const double PI = acos(-1.);
int xc, yc;
int min(int a, int b) { return (a > b ? b : a); }
int max(int a, int b) { return (a > b ? a : b); }
int abs(int a) { return (a < 0 ? -a : a); }
void sort(int a[], int l, int r);
int main() {
  int a[101] = {}, n, k, tmp, tmp2, ans = -1;
  char m[101][101] = {};
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  while (k--) {
    cin >> tmp >> tmp2;
    m[tmp - 1][tmp2 - 1] = m[tmp2 - 1][tmp - 1] = 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int l = j + 1; l < n; l++) {
        if (m[i][j] && m[i][l] && m[j][l]) {
          if (ans == -1 || ans > a[i] + a[j] + a[l]) ans = a[i] + a[j] + a[l];
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
void sort(int a[], int l, int r) {
  int i = l, j = r;
  int x, tmp;
  x = a[(l + r) / 2];
  while (i < j) {
    while (a[i] < x) i++;
    while (a[j] > x) j--;
    if (i <= j) {
      tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
      i++;
      j--;
    }
  }
  if (j > l) sort(a, l, j);
  if (r > i) sort(a, i, r);
}
