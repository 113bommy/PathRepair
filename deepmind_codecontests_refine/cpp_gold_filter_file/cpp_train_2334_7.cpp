#include <bits/stdc++.h>
using namespace std;
int k;
int q[20], cp, p[10];
char a[4];
int main() {
  scanf("%d", &k);
  cp = 0;
  k *= 2;
  memset(p, 0, sizeof(p));
  for (int i = 0; i < 4; i++) {
    scanf("%s", a);
    for (int j = 0; j < 4; j++)
      if (a[j] != '.') p[a[j] - '0']++;
  }
  int flag = 1;
  for (int i = 1; i <= 9; i++) {
    if (p[i] > k) {
      flag = 0;
    }
  }
  if (flag)
    puts("YES");
  else
    puts("NO");
  return 0;
}
