#include <bits/stdc++.h>
using namespace std;
const int xx[] = {0, 1, 0, -1, -1, 1, -1, 1};
const int yy[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};
int Male[500];
int Female[500];
int main() {
  int n, x, y, z, l, a, b, i, j, p, r, k, mx, high, mid, low, m, t, q;
  long long int ans = 0;
  char ch, ch1;
  bool key = 1, flag = 1;
  scanf("%d", &n);
  getchar();
  for (i = 0; i < n; i++) {
    scanf("%c", &ch);
    getchar();
    scanf("%d", &a);
    getchar();
    scanf("%d", &b);
    getchar();
    if (ch == 'M') {
      for (j = a; j <= b; j++) {
        Male[j]++;
      }
    } else {
      for (j = a; j <= b; j++) {
        Female[j]++;
      }
    }
  }
  mx = 0;
  for (i = 1; i <= 366; i++) {
    k = min(Male[i], Female[i]);
    mx = max(mx, k * 2);
  }
  printf("%d\n", mx);
  return 0;
}
