#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, ans;
int main() {
  scanf("%d %d %d %d", &a, &b, &c, &d);
  scanf("\n");
  while (1) {
    char c = getchar();
    if (c == -1) break;
    if (c == '1') ans += a;
    if (c == '2') ans += b;
    if (c == '3') ans += c;
    if (c == '4') ans += d;
  }
  printf("%d\n", ans);
}
