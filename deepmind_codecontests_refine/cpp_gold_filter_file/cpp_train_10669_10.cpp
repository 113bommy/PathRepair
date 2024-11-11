#include <bits/stdc++.h>
using namespace std;
int b[2005];
int main() {
  int a[2005], i, n, c[2005], k;
  cin >> n;
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= n; i++) b[a[i]]++;
  k = 2000;
  while (b[k] == 0) k--;
  c[k] = 1;
  for (i = k - 1; i > 0; i--) c[i] = c[i + 1] + 1 + (b[i + 1] - 1);
  for (i = 1; i <= n; i++) cout << c[a[i]] << " ";
  return 0;
}
