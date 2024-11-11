#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, j = 0, i, s, t;
  cin >> n;
  int a[n + 1];
  for (i = 1; i <= n; i++) cin >> a[i];
  s = a[1] + a[n] + n - 1;
  for (i = 1; i < n; i++) s += abs(a[i] - a[i + 1]);
  cout << s;
  return 0;
}
