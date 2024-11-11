#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int main() {
  int n, p;
  char ch[5], ch1;
  int l = -2000000000, r = 2000000000;
  scanf("%d", &n);
  getchar();
  for (int i = 0; i < n; i++) {
    scanf("%s %d %c", ch, &p, &ch1);
    getchar();
    if (ch1 == 'Y') {
      if (strcmp(ch, ">=") == 0) l = max(p, l);
      if (strcmp(ch, "<") == 0) r = min(r, p - 1);
      if (strcmp(ch, "<=") == 0) r = min(r, p);
      if (strcmp(ch, ">") == 0) l = max(p + 1, l);
    }
    if (ch1 == 'N') {
      if (strcmp(ch, ">=") == 0) r = min(r, p - 1);
      if (strcmp(ch, "<") == 0) l = max(p, l);
      if (strcmp(ch, "<=") == 0) l = max(p + 1, l);
      if (strcmp(ch, ">") == 0) r = min(r, p);
    }
  }
  if (l <= r)
    printf("%d\n", r);
  else
    printf("Impossible\n");
  return 0;
}
