#include <bits/stdc++.h>
int n;
int m;
char str[3000100];
int preveri(int x) {
  int stevec = 0;
  if (x - 1 >= 0 && str[x - 1] == '.') {
    stevec++;
  }
  if (x + 1 < n && str[x + 1] == '.') {
    stevec++;
  }
  return stevec;
}
int main() {
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%s", str);
  int vsota = 0;
  for (int i = 1; i < n; i++) {
    if (str[i - 1] == '.' && str[i] == '.') {
      vsota++;
    }
  }
  for (int i = 0; i < m; i++) {
    int x;
    char c;
    scanf("%d %c", &x, &c);
    int a = preveri(x - 1);
    if (c == '.' && str[x - 1] != '.') {
      vsota = vsota + a;
    } else if (c != '.' && str[x - 1] == '.') {
      vsota = vsota - a;
    }
    str[x - 1] = c;
    printf("%d\n", vsota);
  }
  return 0;
}
