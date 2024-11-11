#include <bits/stdc++.h>
using namespace std;
char s[2333333];
int a[2333333], b[2333333], na, nb, L, R;
int sum[10][2333333];
long long ans;
void read(int &n, int a[2333333]) {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'R') a[i] = 1;
    if (s[i] == 'B') a[i] = 0;
    if (s[i] == 'G') a[i] = 2;
  }
}
int main() {
  read(na, a);
  read(nb, b);
  for (int i = 2; i <= nb; i++) sum[b[i - 1] + 3 * b[i]][i]++;
  for (int d = 0; d < 9; d++)
    for (int i = 1; i <= nb; i++) sum[d][i] += sum[d][i - 1];
  L = 1;
  R = 1;
  for (int i = 1; i <= na; i++) {
    while (a[i] != b[R] && R <= nb) R++;
    R = min(R, nb);
    if (a[i] == a[i - 1] || i == 1)
      ans += R - L + 1;
    else {
      int d = 3 * a[i - 1] + a[i];
      ans += sum[d][R] - sum[d][L - 1] + R - L + 1;
    }
    if (a[i] == b[L] && L <= nb) L++;
    if (a[i] == b[R] && R <= nb) R++;
    R = min(R, nb);
    if (L > nb) break;
  }
  printf("%I64d\n", ans);
}
