#include <bits/stdc++.h>
using namespace std;
int n;
char a[100005];
char b[100005];
int z, o, ez, eo;
int main() {
  scanf("%d", &n);
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] == '1') {
      o++;
      if (b[i] == '0') eo++;
    } else {
      z++;
      if (b[i] == '0') ez++;
    }
  }
  printf("%I64d", (long long)ez * o + (long long)eo * (z - ez));
}
