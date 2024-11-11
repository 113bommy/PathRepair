#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, l, r, k;
  cin >> n >> k;
  int a[k + 1];
  memset(a, 0, sizeof(a));
  for (i = 0; i < n; i++) {
    cin >> l >> r;
    a[l - 1]++;
    a[r]--;
  }
  for (i = 1; i < k; i++) a[i] += a[i - 1];
  int count = 0;
  for (i = 0; i < k; i++)
    if (!a[i]) count++;
  cout << count << "\n";
  for (i = 0; i < k; i++)
    if (!a[i]) cout << i + 1 << " ";
  return 0;
}
