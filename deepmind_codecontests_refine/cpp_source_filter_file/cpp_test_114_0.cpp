#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, a[N];
bool tong[10 * N];
void work() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    tong[a[i]] = 1;
  }
  sort(a + 1, a + 1 + n);
  int m = unique(a + 1, a + 1 + n) - a;
  int t = min(n / 2, m);
  for (int i = 2; i <= t + 1; i++) {
    printf("%d %d\n", a[1], a[i]);
  }
  for (int i = 2; i <= m && t < n / 2; i++) {
    for (int j = i + 1; j <= m && t < n / 2; j++) {
      if (tong[a[j] % a[i]]) continue;
      printf("%d %d\n", a[j], a[i]);
      t++;
    }
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) work();
}
