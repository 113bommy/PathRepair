#include <bits/stdc++.h>
using namespace std;
int n;
const int sz = 2e5 + 9;
char a[sz];
int f[10];
int main() {
  scanf("%d %s", &n, a);
  for (int i = 1; i <= 9; i++) scanf("%d", &f[i]);
  for (int i = 0; i < n; i++) {
    int m = a[i] - '0';
    if (f[m] > m) {
      a[i] = f[m] + '0';
      int j = i + 1;
      while (j < n && f[a[j] - '0'] > a[j] - '0') {
        a[j] = f[a[j] - '0'] + '0';
        j++;
      }
      break;
    }
  }
  for (int i = 0; i < n; i++) printf("%c", a[i]);
  return 0;
}
