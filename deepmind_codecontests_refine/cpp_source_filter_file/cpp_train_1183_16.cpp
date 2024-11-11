#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a.begin(), a.end());
  if (n < k)
    cout << -1 << "\n";
  else if (n - k > 0)
    cout << a[n - k] << " " << a[n - k] << "\n";
  else
    cout << 1000000000 << " " << 100000000 << "\n";
  return 0;
}
