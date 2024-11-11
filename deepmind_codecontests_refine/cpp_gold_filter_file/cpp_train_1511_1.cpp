#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000006;
int a[maxn];
int main() {
  int n, x;
  cin >> n;
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    a[x]++;
  }
  int ans = 0;
  for (int i = 0; i < maxn; i++) {
    if (a[i]) {
      a[i + 1] += a[i] / 2;
      a[i] %= 2;
      if (a[i]) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
