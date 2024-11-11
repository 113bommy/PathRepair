#include <bits/stdc++.h>
using namespace std;
char a[10][10];
int f[2];
void first(char q) {
  if (q == '.' || q == 'K' || q == 'k') return;
  int fl = !('a' <= q && q <= 'z');
  if (fl) q = q - 'A' + 'a';
  if (q == 'q') f[fl] += 9;
  if (q == 'r') f[fl] += 5;
  if (q == 'b' || q == 'n') f[fl] += 3;
  if (q == 'p') f[fl]++;
}
int main() {
  int i = 0;
  scanf("%s", a[i++]);
  scanf("%s", a[i++]);
  scanf("%s", a[i++]);
  scanf("%s", a[i++]);
  scanf("%s", a[i++]);
  scanf("%s", a[i++]);
  scanf("%s", a[i++]);
  scanf("%s", a[i++]);
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) first(a[i][j]);
  if (f[0] == f[1])
    puts("Draw");
  else
    puts(f[0] < f[1] ? "White" : "Black");
}
