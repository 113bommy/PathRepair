#include <bits/stdc++.h>
using namespace std;
int n, k, x, a[101], s;
int main() {
  cin >> n >> k >> x;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n - k; i++) s = s + a[i];
  s = s + x * k;
  cout << s;
  return 0;
}
