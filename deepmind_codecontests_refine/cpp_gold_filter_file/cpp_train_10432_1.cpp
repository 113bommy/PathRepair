#include <bits/stdc++.h>
using namespace std;
const int maxN = 2048;
int a[maxN][maxN];
int b[maxN], c[maxN];
int u[maxN], v[maxN];
int n;
char s[maxN][maxN];
int main() {
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) gets(s[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) a[i][j] = s[i][j] - '0';
  int res = 0;
  for (int i = 0; i + 1 < n; i++)
    for (int j = n - 1; j > i; j--)
      if ((b[i] + c[j] + a[i][j]) % 2 == 1) {
        res++;
        b[i]++, c[j]++;
        u[i]++, v[j]++;
      }
  for (int i = 0; i < n; i++) b[i] = c[i] = 0;
  for (int i = n - 1; i > 0; i--)
    for (int j = 0; j < i; j++)
      if ((b[i] + c[j] + a[i][j]) % 2 == 1) {
        res++;
        b[i]++, c[j]++;
        u[i]++, v[j]++;
      }
  for (int i = 0; i < n; i++)
    if ((u[i] + v[i] + a[i][i]) % 2 == 1) res++;
  printf("%d\n", res);
  return 0;
}
