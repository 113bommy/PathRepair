#include <bits/stdc++.h>
using namespace std;
int n, Pos;
long long a[500005], Out;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    long long x;
    scanf("%I64d", &x);
    while (Pos > 1 && a[Pos - 1] >= a[Pos] && a[Pos] <= x) {
      Out += min(x, a[Pos - 1]);
      Pos--;
    }
    a[++Pos] = x;
  }
  sort(a + 1, a + 1 + Pos);
  for (int i = 1; i <= Pos - 2; i++) Out += a[i];
  printf("%I64d", Out);
  return 0;
}
