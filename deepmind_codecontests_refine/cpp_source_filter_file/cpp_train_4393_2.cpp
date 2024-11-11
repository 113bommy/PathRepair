#include <bits/stdc++.h>
using namespace std;
char c[110000];
int n, k, cnt;
int p[110000];
void print() {
  for (int i = 1; i <= n; i++) printf("%c", c[i]);
  printf("\n");
}
int main() {
  scanf("%d%d\n", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%c", &c[i]);
  cnt = 0;
  for (int i = 1; i < n; i++)
    if (c[i] == '4' && c[i + 1] == '7') p[++cnt] = i;
  for (int i = 1; i <= cnt && k > 0; i++, k--) {
    if (p[i] % 2 == 0 && c[p[i] - 1] == '4') {
      if (k % 2 == 1) c[p[i]] = '7';
      print();
      return 0;
    }
    if (p[i] % 2 == 1 && c[p[i] + 2] == '7') {
      if (k & 2 == 1) c[p[i] + 1] = '4';
      print();
      return 0;
    }
    if (p[i] % 2 == 1)
      c[p[i] + 1] = '4';
    else
      c[p[i]] = '7';
  }
  print();
  return 0;
}
