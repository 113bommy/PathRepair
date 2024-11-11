#include <bits/stdc++.h>
using namespace std;
int fact[1000003];
void divisor() {
  for (int i = 2; i < 1000003; i++) {
    for (int j = i; j < 1000003; j += i) fact[j]++;
  }
  return;
}
int main() {
  divisor();
  int a, b, c, i, j, k;
  while (scanf("%d %d %d", &a, &b, &c) != EOF) {
    int ans = 0;
    for (i = 1; i <= a; i++) {
      for (j = 1; j <= b; j++) {
        for (k = 1; k <= c; k++) {
          ans =
              (ans % 1073741824 + (fact[i * j * k]) % 1073741824) % 1073741824;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
