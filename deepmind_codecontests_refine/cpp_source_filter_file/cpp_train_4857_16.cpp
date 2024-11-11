#include <bits/stdc++.h>
using namespace std;
const int N = 20007, mz = 1e9 + 7;
char s[N], t[N], tmp[N], ans[N];
int n, top;
void shift(int x) {
  ans[++top] = x;
  for (int i = 1; i <= x; i++) tmp[i] = s[n - i + 1];
  for (int i = x + 1; i <= n; i++) tmp[i] = s[i - x];
  strcpy(s + 1, tmp + 1);
}
int main() {
  scanf("%d%s%s", &n, s + 1, t + 1);
  for (int i = 1; i <= n; i++) {
    int j = 1;
    while (j <= n - i + 1 && s[j] != t[i]) j++;
    if (j > n - i + 1) return 0 * puts("-1");
    shift(n - j);
    shift(1);
    shift(n);
  }
  printf("%d\n", top);
  for (int i = 1; i <= top; i++) printf("%d%c", ans[i], i == top ? '\n' : ' ');
  return 0;
}
