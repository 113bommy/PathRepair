#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200010;
char a[MAX_N], b[MAX_N];
int num[30], pos[26][MAX_N];
double sum[26][MAX_N], rum[26][MAX_N];
int main(void) {
  int n;
  int i, j;
  double ans = 0, res = 0;
  scanf("%d", &n);
  scanf("%s%s", a, b);
  for (i = 1; i <= n; i++) {
    res += (double)i * i;
  }
  for (i = 0; i < n; i++) {
    int x = b[i] - 'A';
    pos[x][++num[x]] = i + 1;
  }
  for (i = 0; i < 26; i++) {
    for (j = 1; j <= num[i]; j++) sum[i][j] = sum[i][j - 1] + pos[i][j];
  }
  for (i = 0; i < 26; i++) {
    for (j = num[i]; j >= 1; j--) rum[i][j] = rum[i][j + 1] + n - pos[i][j] + 1;
  }
  for (i = 0; i < n; i++) {
    int x = a[i] - 'A';
    int t = upper_bound(pos[x] + 1, pos[x] + num[x] + 1, i + 1) - pos[x];
    t--;
    ans += sum[x][t] * (double)(n - i);
    ans += rum[x][t + 1] * (double)(i + 1);
  }
  double a1 = ans, a2 = res;
  printf("%.9f\n", a1 / a2);
  return 0;
}
