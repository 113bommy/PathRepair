#include <bits/stdc++.h>
using namespace std;
int n, vet[202020], ans;
int main() {
  scanf("%d", &n);
  for (int(i) = (0); (i) < (n); (i)++) {
    scanf("%d", vet + i);
    if (i) vet[i] += vet[i - 1];
  }
  ans = vet[n - 1];
  for (int(i) = (n - 3); (i) >= (0); (i)--) ans = max(ans, vet[i + 1] - ans);
  printf("%d\n", ans);
}
