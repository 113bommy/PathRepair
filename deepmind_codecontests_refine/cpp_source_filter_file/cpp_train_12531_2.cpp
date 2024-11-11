#include <bits/stdc++.h>
using namespace std;
int T;
int main() {
  scanf("%d", &T);
  while (T--) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b) {
      int aux = a;
      a = b;
      b = a;
    }
    int ans = 0;
    while (a && b) {
      int h = b / a;
      ans += h;
      b -= h * a;
      int aux = a;
      a = b;
      b = aux;
    }
    printf("%d\n", ans);
  }
  return 0;
}
