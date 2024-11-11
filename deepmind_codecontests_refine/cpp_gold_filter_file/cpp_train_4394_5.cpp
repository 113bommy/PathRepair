#include <bits/stdc++.h>
using namespace std;
char str[200010];
int tim[200010];
int main() {
  memset(tim, 0x3f, sizeof(tim));
  int n, k;
  scanf("%d %d", &n, &k);
  scanf("%s", str);
  for (int i = 0; i < n; i++)
    if (str[i] == str[(i + 1) % n] || str[i] == str[(i - 1 + n) % n])
      tim[i] = 0;
  for (int i = 0; i < 2 * n; i++)
    tim[i % n] = min(tim[i % n], tim[(i - 1 + n) % n] + 1);
  for (int i = 2 * n - 1; i >= 0; i--)
    tim[i % n] = min(tim[i % n], tim[(i + 1) % n] + 1);
  for (int i = 0; i < n; i++)
    if (min(tim[i], k) & 1)
      printf("%c", 'W' + 'B' - str[i]);
    else
      printf("%c", str[i]);
  printf("\n");
  return 0;
}
