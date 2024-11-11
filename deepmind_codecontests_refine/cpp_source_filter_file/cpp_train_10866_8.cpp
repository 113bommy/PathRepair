#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int inc[n + 1], dec[n + 1];
  inc[n] = 1;
  dec[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] <= a[i - 1])
      dec[i] = dec[i - 1] + 1;
    else
      dec[i] = 1;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] <= a[i + 1])
      inc[i] = inc[i - 1] + 1;
    else
      inc[i] = 1;
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    if (inc[l] + dec[r] > r - l + 1)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
