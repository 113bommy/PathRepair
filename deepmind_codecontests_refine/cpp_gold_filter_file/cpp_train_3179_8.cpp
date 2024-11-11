#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) { return a > b; }
int main() {
  int a[1100];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int b[1100];
  int l = 0, r = n - 1, i = 0;
  while (l < r) b[i] = a[l], b[i + 1] = a[r], r--, l++, i += 2;
  if (l == r) b[i] = a[l];
  for (int i = 0; i < n; i++) cout << b[i] << " ";
  return 0;
}
