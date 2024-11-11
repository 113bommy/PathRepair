#include <bits/stdc++.h>
using namespace std;
int n, m, wynik, sumek, T[104], a, b;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &T[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &a, &b);
    sumek = 0;
    for (int j = a; j <= b; j++) sumek += T[j];
    if (sumek > 0) wynik += sumek;
  }
  printf("%d\n", max(0, wynik));
  getchar();
  getchar();
  return 0;
}
