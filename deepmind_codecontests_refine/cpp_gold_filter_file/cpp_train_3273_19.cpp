#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, freq[100001]{0}, x, *away, i;
  scanf("%d", &n);
  away = new int[n];
  for (i = 0; i < n; ++i) {
    scanf("%d%d", &x, away + i);
    ++freq[x];
  }
  for (i = 0; i < n; ++i)
    printf("%d %d\n", n - 1 + freq[away[i]], n - 1 - freq[away[i]]);
  return 0;
}
