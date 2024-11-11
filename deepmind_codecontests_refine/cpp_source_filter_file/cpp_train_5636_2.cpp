#include <bits/stdc++.h>
using namespace std;
int a[10];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; ++i) a[i % 9]++;
    long long ans = 0;
    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j) ans += a[i] * a[j] * a[(i * j) % 9];
    for (int i = 1; i <= n; ++i)
      for (int j = i; j <= n; j += i) ans--;
    cout << ans << endl;
  }
  return 0;
}
