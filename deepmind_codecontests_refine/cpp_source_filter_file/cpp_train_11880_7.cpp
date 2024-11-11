#include <bits/stdc++.h>
using namespace std;
int a[200010], b[200010], n, cnt = 0;
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 2; i <= n; i++) cin >> a[i];
  for (int tmp = n; tmp; tmp = a[tmp]) b[++cnt] = tmp;
  reverse(b + 1, b + cnt + 1);
  for (int i = 1; i <= n; i++) cout << b[i] << " ";
  return 0;
}
