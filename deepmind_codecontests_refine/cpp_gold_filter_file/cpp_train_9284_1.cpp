#include <bits/stdc++.h>
using namespace std;
int T, s[300010];
char S[300010];
int main() {
  scanf("%d", &T);
  for (int i1 = 1; i1 <= T; i1++) {
    int a, b;
    scanf("%d%d", &a, &b);
    scanf("%s", S + 1);
    int n = strlen(S + 1), t = 0;
    for (int i = 1; i <= n; i++)
      if (S[i] == '.') {
        if (i == 1 || S[i] != S[i - 1])
          s[++t] = 1;
        else
          s[t]++;
      }
    int s1 = 0, s2 = 0, s3 = 0, x = 0;
    for (int i = 1; i <= t; i++)
      if (s[i] >= b && s[i] < a)
        s1++;
      else if (s[i] >= a && s[i] < 2 * b)
        s2++;
      else if (s[i] >= 2 * b)
        s3++, x = s[i];
    if (s1 == 0 && s2 == 0 && s3 == 0)
      puts("NO");
    else if (s3 > 1 || s1 >= 1)
      puts("NO");
    else if (s3 == 0)
      puts((s2 & 1) ? "YES" : "NO");
    else {
      if (x >= 4 * b + a - 1)
        puts("NO");
      else {
        if (s2 & 1) {
          if (x - a < a || a > 2 * b - 1 || x - a - 2 * b + 1 >= b)
            puts("NO");
          else
            puts("YES");
        } else {
          if (x - a < 2 * b - 1 || (x - a) >= 2 * a)
            puts("YES");
          else
            puts("NO");
        }
      }
    }
  }
  return 0;
}
