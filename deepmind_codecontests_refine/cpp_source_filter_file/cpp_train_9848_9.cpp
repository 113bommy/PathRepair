#include <bits/stdc++.h>
using namespace std;
int a[3000];
int main() {
  int n, k, s = 0, i;
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> a[i];
  sort(a, a + n);
  for (i = 1; i <= k; i++) s = s + a[i];
  cout << s;
  return 0;
}
