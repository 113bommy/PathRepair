#include <bits/stdc++.h>
using namespace std;
const int max_n = 100005;
int n;
char a[max_n];
int cnt[3][max_n];
int main() {
  scanf("%s", a);
  while (a[n] != '\0') n++;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) cnt[j][i + 1] = cnt[j][i];
    cnt[a[i] - 'x'][i + 1]++;
  }
  int q, l, r;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d%d", &l, &r);
    l--;
    r--;
    int c[3];
    for (int j = 0; j < 3; j++) c[j] = cnt[j][r + 1] - cnt[j][l];
    int Mx = max(c[0], max(c[1], c[2]));
    int mx = min(c[0], min(c[1], c[2]));
    if (r - l <= 1 or Mx - mx <= 1)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
