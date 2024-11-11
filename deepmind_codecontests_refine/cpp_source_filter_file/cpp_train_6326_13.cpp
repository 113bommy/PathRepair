#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int i, j;
  int s, t;
  int a[110];
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> a[i];
  a[n + 1] = k + 1;
  s = 0;
  i = 1;
  while (a[i] <= k) {
    i = i + 1;
    s = s + 1;
  }
  j = n;
  a[0] = k + 1;
  while (a[j] <= k) {
    j = j - 1;
    t = t + 1;
  }
  if (i == n + 1)
    cout << s << endl;
  else
    cout << s + t << endl;
  return 0;
}
