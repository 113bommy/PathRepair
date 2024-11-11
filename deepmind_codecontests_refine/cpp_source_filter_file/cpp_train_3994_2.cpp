#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005];
int main() {
  int n, i, j, k, ap = 0;
  cin >> n >> k;
  for (i = 0; i < n; ++i) cin >> a[i];
  i = 0;
  j = -1;
  while (ap < k && j < n)
    if (b[a[++j]]++ == 0) ap++;
  if (j == n) {
    cout << -1 << " " << -1;
    return 0;
  }
  while (b[a[i]]--) i++;
  cout << i + 1 << " " << j + 1;
}
