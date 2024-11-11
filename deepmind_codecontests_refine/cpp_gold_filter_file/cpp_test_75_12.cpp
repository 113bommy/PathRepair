#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 3;
int a[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int l = 1, r = n;
  while (l < n && a[l] < a[l + 1]) l++;
  while (r > 1 && a[r] < a[r - 1]) r--;
  cout << ((l & 1) || ((n - r + 1) & 1) ? "Alice\n" : "Bob\n");
  return 0;
}
