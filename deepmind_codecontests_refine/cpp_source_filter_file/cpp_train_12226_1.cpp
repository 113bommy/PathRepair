#include <bits/stdc++.h>
using namespace std;
int a[2010];
int main() {
  int n, k;
  cin >> n >> k;
  if ((n * (n - 1)) / 2 == n * k) {
    cout << n * k << endl;
    for (int i = 1; i <= n; i++) a[i] = i;
    for (int i = n + 1; i <= 2 * n; i++) a[i] = a[i - n];
    int s = 2, e = 1 + k;
    for (int i = 1; i <= n; i++) {
      for (int j = s; j <= e; j++) printf("%d %d\n", i, a[j]);
      s++, e++;
    }
  } else
    printf("-1\n");
  return 0;
}
