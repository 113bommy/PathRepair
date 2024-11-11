#include <bits/stdc++.h>
using namespace std;
const int MAX = 205;
int n, ans[MAX];
char a[MAX];
int main() {
  scanf("%d", &n);
  scanf("%s", a + 1);
  for (int i = 1; i <= n; i++) {
    if (!ans[i]) ans[i] = 2;
    for (int j = i + 1; j <= n; j++) {
      if (a[i] > a[j]) {
        if (ans[i] == ans[j]) {
          printf("NO");
          return 0;
        }
        ans[j] = ans[i] ^ 1;
      }
    }
  }
  printf("YES\n");
  for (int i = 1; i <= n; i++) printf("%d", ans[i] - 2);
  return 0;
}
