#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, ans;
int main() {
  scanf("%d%d%d%d", &a, &b, &c, &d);
  scanf("\n");
  while (1) {
    char x = getchar();
    if (x == -1) break;
    if (x == '1') ans += a;
    if (x == '2') ans += b;
    if (x == '3') ans += c;
    if (x == '4') ans += d;
  }
  printf("%d\n", ans);
}
