#include <bits/stdc++.h>
using namespace std;
int n, s[120], c[120][120], tota, totb, sta[120], top;
void deal(int a[], int p) {
  if (p & 1) sta[++top] = a[(p + 1) / 2];
  for (int i = 1; i <= p / 2; i++) tota += a[i];
  for (int i = (p + 1) / 2 + 1; i <= p; i++) totb += a[i];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", s + i);
    for (int j = 1; j <= s[i]; j++) scanf("%d", &c[i][j]);
    deal(c[i], s[i]);
  }
  sort(sta + 1, sta + top + 1);
  for (int i = top; i >= 1; i--)
    if ((top - i) & 1)
      totb += sta[i];
    else
      tota += sta[i];
  printf("%d %d\n", tota, totb);
}
