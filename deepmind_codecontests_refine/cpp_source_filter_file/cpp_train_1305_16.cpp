#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (c == 0 && a == b) {
    printf("YES\n");
    return 0;
  }
  if (c == 0) {
    printf("NO\n");
    return 0;
  }
  if ((b - a) % c == 0 && (b - a) / c > 0) {
    printf("YES\n");
    return 0;
  }
  printf("NO\n");
  return 0;
}
