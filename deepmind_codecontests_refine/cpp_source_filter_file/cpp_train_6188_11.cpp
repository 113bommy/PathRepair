#include <bits/stdc++.h>
using namespace std;
int n;
long long a, b, w, x;
int main() {
  while (scanf("%d", &n) != EOF) {
    cin >> a >> b;
    for (int i = 1; i <= n; i++) {
      scanf("%I64d", &w);
      x = w * a / b;
      x = x * b / a;
      printf("%I64d%c", (w - x) / a, " \n"[i == n]);
    }
  }
  return 0;
}
