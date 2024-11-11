#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
char f[maxn][55], s[maxn][55], com[55];
int n, a;
int main() {
  scanf("%d", &n);
  getchar();
  for (int i = 1; i <= n; i++) {
    scanf("%s %s", f[i], s[i]);
    if (strcmp(f[i], s[i]) > 0) {
      strcpy(com, f[i]);
      strcpy(f[i], s[i]);
      strcpy(s[i], com);
    }
  }
  scanf("%d", &a);
  strcpy(com, f[a]);
  int mark = 0;
  for (int i = 2; i <= n; i++) {
    scanf("%d", &a);
    if (strcmp(com, f[a]) < 0) {
      strcpy(com, f[a]);
    } else if (strcmp(com, s[a]) < 0) {
      strcpy(com, s[a]);
    } else {
      mark = 1;
    }
  }
  if (mark == 1)
    printf("NO\n");
  else
    printf("YES\n");
  return 0;
}
