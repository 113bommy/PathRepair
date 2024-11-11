#include <bits/stdc++.h>
using namespace std;
int t;
int n, m;
int a[1001];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    long long temp = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      temp += a[i];
    }
    if (n != m)
      cout << -1 << endl;
    else if (n == 2 && m == 2)
      cout << -1 << endl;
    else {
      printf("%d\n", temp * 2);
      for (int i = 1; i <= n - 1; i++) printf("%d %d\n", i, i + 1);
      printf("%d %d\n", n, 1);
    }
  }
}
