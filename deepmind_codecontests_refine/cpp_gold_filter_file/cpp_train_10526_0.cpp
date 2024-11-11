#include <bits/stdc++.h>
using namespace std;
int n;
char s[100], t[100];
int main() {
  scanf("%d", &n);
  printf("%d %d\n", 1, 0);
  fflush(stdout);
  scanf("%s", t + 1);
  int l = 1, r = 1e9;
  for (int i = 2; i <= n; i++) {
    int mid = (l + r) >> 1;
    printf("%d %d\n", 1, mid);
    fflush(stdout);
    scanf("%s", s + 1);
    if (s[1] == t[1])
      l = mid;
    else
      r = mid;
  }
  printf("%d %d %d %d\n", 0, l, 2, r);
  fflush(stdout);
}
