#include <bits/stdc++.h>
using namespace std;
double ans;
int p, i, X, Y, h[500005];
char s[500005];
double f[500005], sum[500005];
int main() {
  scanf("%s", s);
  p = strlen(s);
  for (i = p; i >= 0; i--) f[i] = f[i + 1] + (p - i + 1) / (i + 0.0);
  for (i = 1; i <= p; i++) sum[i] = sum[i - 1] + 1 / (i + 0.0);
  for (i = 0; i < p; i++)
    if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
        s[i] == 'U' || s[i] == 'Y') {
      h[max(i + 1, p - (i + 1) + 1)]++;
    }
  for (i = 3; i <= p; i++) {
    X = p - i + 1;
    Y = i;
    if (X == Y)
      ans += h[i] * (X + f[Y + 1]);
    else
      ans += h[i] * ((X + f[Y]) + (p - i + 1) * (sum[Y - 1] - sum[X]));
  }
  printf("%.10f", ans);
  return 0;
}
