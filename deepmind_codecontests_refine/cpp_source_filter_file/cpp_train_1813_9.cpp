#include <bits/stdc++.h>
using namespace std;
int a[1001];
int main() {
  int n, inv = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      if (a[i] > a[j]) ++inv;
  if (inv % 2 == 0)
    cout << fixed << setprecision(6) << 2.0 * inv / 2 << endl;
  else
    cout << fixed << setprecision(6) << 2.0 * inv - 1 << endl;
  return 0;
}
