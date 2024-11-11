#include <bits/stdc++.h>
using namespace std;
int s0, s1, mn, z;
char a[5009];
char b[5009];
int main() {
  scanf("%s", a);
  scanf("%s", b);
  s0 = strlen(a);
  s1 = strlen(b);
  mn = s1;
  for (int i = 0 - s1; i < s0; i++) {
    z = 0;
    for (int j = 0; j < s1; j++) {
      if (j < 0 || a[i + j] != b[j] || j + i >= s0) z++;
    }
    mn = min(z, mn);
  }
  printf("%d", mn);
  getchar();
  getchar();
}
