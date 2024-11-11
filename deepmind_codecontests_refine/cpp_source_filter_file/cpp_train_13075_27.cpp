#include <bits/stdc++.h>
using namespace std;
char s[1005], t[1005], mark[1005], current[1005];
int main() {
  int n, m, mini = 9999;
  scanf("%d %d %s %s", &n, &m, s, t);
  for (int i = 0; i <= m - n; i++) {
    int l = 0;
    for (int j = 0; j < n; j++) {
      if (s[j] != t[i + j]) {
        current[l++] = j;
      }
    }
    if (mini > l) {
      mini = l;
      for (int z = 0; z < l; z++) {
        mark[z] = current[z];
      }
    }
  }
  printf("%d\n", mini);
  if (mini > 0) {
    printf("%d", mark[0] + 1);
    for (int i = 1; i < mini; i++) {
      printf(" %d", mark[i] + 1);
    }
    printf("\n");
  }
}
