#include <bits/stdc++.h>
using namespace std;
char bi[2000020];
int main() {
  int n, i, a;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    bi[a]++;
  }
  int t = 0, tot = 0;
  for (i = 0; i < 2000020; i++) {
    if ((bi[i] + t) % 2) tot++;
    t = (bi[i] + t) / 2;
  }
  printf("%d\n", tot);
  return 0;
}
