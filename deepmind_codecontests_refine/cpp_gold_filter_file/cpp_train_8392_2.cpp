#include <bits/stdc++.h>
using namespace std;
const int M = 62;
char st[400010];
char mid[400010], ans[400010];
int g[1000], c[1000];
char ch[1000];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", st);
  for (int i = 'a'; i <= 'z'; i++) g[i] = i - 'a', ch[i - 'a'] = i;
  for (int i = 'A'; i <= 'Z'; i++) g[i] = i - 'A' + 26, ch[i - 'A' + 26] = i;
  for (int i = '0'; i <= '9'; i++) g[i] = i - '0' + 52, ch[i - '0' + 52] = i;
  for (int i = 0; i < n; i++) c[g[st[i]]]++;
  int ord = 0;
  for (int i = 0; i < M; i++)
    if (c[i] & 1) ord++;
  if (!ord) {
    int len = 0;
    for (int i = 0; i < M; i++) {
      for (int j = c[i]; j; j -= 2) st[++len] = ch[i];
    }
    st[len + 1] = '\0';
    printf("1\n%s", st + 1);
    reverse(st + 1, st + len + 1);
    printf("%s\n", st + 1);
  } else {
    for (int i = ord; i <= n; i++)
      if (!(n % i) && ((n / i) & 1) && (i & 1) == (ord & 1)) {
        int k = 0;
        for (int j = 0; j < M; j++)
          if (c[j] & 1) c[j]--, mid[++k] = ch[j];
        for (int j = 0; j < M && k < i; j++) {
          while (c[j] && k < i) {
            c[j]--, mid[++k] = ch[j];
            c[j]--, mid[++k] = ch[j];
          }
        }
        k = 1;
        int L = n / i / 2, now = 0;
        printf("%d\n", i);
        for (int j = 1; j <= i; j++) {
          for (int k = 1; k <= L; k++) {
            while (!c[now]) now++;
            ans[k] = ch[now];
            c[now] -= 2;
          }
          ans[L + 1] = '\0';
          printf("%s", ans + 1);
          printf("%c", mid[j]);
          reverse(ans + 1, ans + L + 1);
          printf("%s", ans + 1);
          putchar(j == i ? '\n' : ' ');
        }
        break;
      }
  }
  return 0;
}
