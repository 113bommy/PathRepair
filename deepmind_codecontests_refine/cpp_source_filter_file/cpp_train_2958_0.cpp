#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, ar[102] = {0}, ar2[102] = {0};
  cin >> n >> m;
  for (int i = 0; i < n; i++) scanf("%d", &ar[i]);
  sort(ar, ar + n);
  for (int i = 0; i < m; i++) scanf("%d", &ar2[i]);
  sort(ar2, ar2 + n);
  int val = max(ar[n - 1], 2 * ar[0]);
  if (val < ar2[0])
    cout << val;
  else
    cout << "-1";
  return 0;
}
