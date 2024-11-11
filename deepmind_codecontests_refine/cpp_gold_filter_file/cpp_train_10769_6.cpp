#include <bits/stdc++.h>
using namespace std;
const int nMax = 1e5 + 10;
int a[nMax], b[nMax];
char s[nMax];
int main() {
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < n; i++) a[i] = s[i] - '0';
  reverse(a, a + n);
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; i++) b[i] = s[i] - '0';
  reverse(b, b + n);
  for (int i = nMax - 2; i > 0; i--) {
    int x = i;
    while (x < nMax && a[x] && a[x - 1]) {
      a[x + 1] = 1, a[x] = 0, a[x - 1] = 0;
      x += 2;
    }
  }
  for (int i = nMax - 2; i > 0; i--) {
    int x = i;
    while (x < nMax && b[x] && b[x - 1]) {
      b[x + 1] = 1, b[x] = 0, b[x - 1] = 0;
      x += 2;
    }
  }
  int flag = 0;
  for (int i = nMax - 1; i >= 0; i--) {
    if (a[i] > b[i]) {
      flag = 1;
      break;
    } else if (a[i] < b[i]) {
      flag = -1;
      break;
    }
  }
  if (flag == 1)
    puts(">");
  else if (flag == -1)
    puts("<");
  else
    puts("=");
  return 0;
}
