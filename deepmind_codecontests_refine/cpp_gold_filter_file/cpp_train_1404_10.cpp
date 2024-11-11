#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  pair<int, int> a[n + 2];
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  a[0].first = 0;
  a[n + 1].first = 100000;
  sort(a + 1, a + n + 2);
  for (int i = 1; i <= n + 1; i++) {
    a[i].first += a[i - 1].first;
    if (a[i].first > k) {
      printf("%d\n", i - 1);
      for (int j = 1; j < i; j++)
        printf("%d%c", a[j].second, (j == i - 1) ? '\n' : ' ');
      return 0;
    }
  }
  return 0;
}
