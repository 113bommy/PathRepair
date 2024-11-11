#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  int n, k;
  string temp;
  scanf("%d%d", &n, &k);
  getline(cin, temp);
  int i;
  for (i = 0; i < n; i++) {
    char c;
    scanf("%c", &c);
    a[i] = c - '0';
  }
  int p = 0;
  int q = 0;
  bool flag = true;
  while (p < n - 1 && q < k) {
    if (a[p] == 4 && a[p + 1] == 7) {
      q++;
      if ((p % 2) == 0) {
        a[p + 1] = 4;
        p++;
      } else {
        a[p] = 7;
        if ((p > 0) && (a[p - 1] == 4)) {
          flag = false;
          break;
        } else {
          p += 2;
        }
      }
    } else {
      p++;
    }
  }
  if (flag == false) {
    if (((k - p) % 2) == 1) {
      a[p] = 4;
    }
  }
  for (i = 0; i < n; i++) {
    printf("%d", a[i]);
  }
  printf("\n");
  return 0;
}
