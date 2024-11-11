#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int T, n, w[N], l[N], a[N];
char s[2];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      printf("? %d %d\n", i + i - 1, i + i), fflush(stdout);
      scanf("%s", s);
      w[i] = i + i - 1;
      l[i] = i + i;
      if (s[0] == '<') swap(w[i], l[i]);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        printf("? %d %d\n", l[i], l[j]), fflush(stdout);
        scanf("%s", s);
        if (s[0] == '<') swap(l[i], l[j]), swap(w[i], w[j]);
      }
    }
    for (int i = 1; i <= n; i++) a[i + i - 1] = w[i];
    for (int i = 1; i <= n; i++) a[i + i] = l[i];
    for (int i = 3; i <= n + n; i++) {
      for (int j = i + 1; j <= n + n; j++) {
        printf("? %d %d\n", a[i], a[j]), fflush(stdout);
        scanf("%s", s);
        if (s[0] == '<') swap(a[i], a[j]);
      }
    }
    if (l[2] == a[n + 2]) {
      printf("? %d %d\n", l[1], a[n + 1]), fflush(stdout);
      scanf("%s", s);
    }
    puts("!"), fflush(stdout);
  }
}
