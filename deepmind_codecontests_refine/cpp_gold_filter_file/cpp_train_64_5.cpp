#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[100010];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int maxn = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] <= 500000)
      maxn = max(a[i] - 1, maxn);
    else
      maxn = max(1000000 - a[i], maxn);
  }
  cout << maxn << endl;
  return 0;
}
