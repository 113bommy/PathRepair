#include <bits/stdc++.h>
using namespace std;
int p[5000], b[5000], c[5000], d[5000], a[5000];
bool Check(int n) {
  bool check = 1;
  for (int i = 0; i < n && check == 1; ++i) check = (p[b[i]] == i);
  if (check)
    for (int i = 0; i < n; ++i) a[i] = p[i];
  return check;
}
int main() {
  int n, ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    printf("0 %d\n", i);
    fflush(stdout);
    scanf("%d", &c[i]);
  }
  for (int i = 0; i < n; ++i) {
    printf("%d 0\n", i);
    fflush(stdout);
    scanf("%d", &d[i]);
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) b[i] = (k ^ c[i]);
    for (int i = 0; i < n; ++i) p[i] = (d[i] ^ b[0]);
    ans += Check(n);
  }
  printf("!\n%d\n", ans);
  for (int i = 0; i < n; ++i) printf("%d ", a[i]);
  printf("\n");
  fflush(stdout);
  return 0;
}
