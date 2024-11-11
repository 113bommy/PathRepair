#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main() {
  scanf("%d %d %d", &a, &b, &c);
  if (c == 0 && a != b) {
    printf("NO\n");
    return 0;
  }
  if (c == 0 && a == b) {
    printf("YES\n");
    return 0;
  }
  if ((b - a) % c == 0 && (b - a) / c >= 0)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
