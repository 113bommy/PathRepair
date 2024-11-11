#include <bits/stdc++.h>
using namespace std;
int i, n, a[100005], m, cnt = 0;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  i = 1;
  while (i < n) {
    int pos = upper_bound(a + i + 1, a + n + 1, a[i]) - a, t = a[i], c, j, cc;
    c = pos - i >> 1;
    cc = c;
    j = pos;
    while (cc) {
      cc--;
      j--;
      a[j] = t + 1;
    }
    i = j;
    while (c) {
      c--;
      j--;
      a[j] = -1;
    }
  }
  for (i = 1; i <= n; i++)
    if (a[i] != -1) cnt++;
  cout << a[n] - cnt + 1;
  return 0;
}
