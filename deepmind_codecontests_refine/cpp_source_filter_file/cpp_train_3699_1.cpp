#include <bits/stdc++.h>
using namespace std;
int a[256];
char s[10001];
int main() {
  int n, i;
  scanf("%d%s", &n, s);
  for (i = 0; i < n; i++) a[s[i]]++;
  if (a['B'] > 0 && a['G'] > 0 && a['R'] > 0)
    printf("BGR");
  else {
    if (a['B'] == 0 && a['G'] == 0)
      printf("R");
    else if (a['B'] == 0 && a['R'] == 0)
      printf("G");
    else if (a['G'] == 0 && a['R'] == 0)
      printf("B");
    else if (a['R'] > 1 && a['G'] > 1)
      printf("BRG");
    else if (a['R'] > 1 && a['B'] > 1)
      printf("BRG");
    else if (a['B'] > 1 && a['G'] > 1)
      printf("BRG");
    else if (a['B'] == 1 && a['G'] == 1)
      printf("R");
    else if (a['B'] == 1 && a['R'] == 1)
      printf("G");
    else if (a['G'] == 1 && a['R'] == 1)
      printf("B");
    else if (a['B'] > 1)
      printf("GR");
    else if (a['G'] > 1)
      printf("BR");
    else if (a['R'] > 1)
      printf("BG");
  }
  return 0;
}
