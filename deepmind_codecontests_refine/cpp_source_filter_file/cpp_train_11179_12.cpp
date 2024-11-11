#include <bits/stdc++.h>
using namespace std;
int n, k, a[10005];
int main() {
  cin >> n >> k;
  for (int i = 1; i < n; ++i) a[i] = 1;
  for (int i = 1; i <= k; ++i)
    for (int j = 1; j <= n; ++j) {
      int x = i + a[i];
      if (j < n)
        cout << x << ' ';
      else
        cout << x << endl;
      a[i] += a[x];
    }
  return 0;
}
