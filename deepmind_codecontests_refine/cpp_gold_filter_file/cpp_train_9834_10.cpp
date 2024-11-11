#include <bits/stdc++.h>
using namespace std;
int a[15];
char s[50] = "|#.#.#.#.#.#.#.#.#.#.#.|";
int main() {
  int n, i;
  scanf("%d", &n);
  puts("+------------------------+");
  a[0] = n > 4 ? 4 : (n - 1) % 4 + 1;
  n -= 4;
  for (i = 1; i <= n / 3; i++) {
    a[i] = 3;
  }
  if (n > 0) a[i] = n % 3;
  int cnt = 0;
  for (int i = 0; s[i]; i++) {
    if (s[i] == '#' && a[cnt])
      putchar('O'), a[cnt++]--;
    else
      putchar(s[i]);
  }
  puts("D|)");
  cnt = 0;
  for (int i = 0; s[i]; i++) {
    if (s[i] == '#' && a[cnt])
      putchar('O'), a[cnt++]--;
    else
      putchar(s[i]);
  }
  puts(".|");
  if (a[0])
    puts("|O.......................|"), a[0]--;
  else
    puts("|#.......................|");
  cnt = 0;
  for (int i = 0; s[i]; i++) {
    if (s[i] == '#' && a[cnt])
      putchar('O'), a[cnt++]--;
    else
      putchar(s[i]);
  }
  puts(".|)");
  puts("+------------------------+");
  return 0;
}
