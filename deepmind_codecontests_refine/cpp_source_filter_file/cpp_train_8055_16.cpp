#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[11111], b[11111];
bool check() {
  for (int i = 0; i < n; i++)
    if (a[i] > b[m - n + i]) return true;
  return false;
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + n);
  if (check())
    puts("YES");
  else
    puts("NO");
  return 0;
}
