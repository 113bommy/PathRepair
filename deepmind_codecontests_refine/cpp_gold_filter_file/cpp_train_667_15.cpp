#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, V;
  cin >> n >> V;
  int a[25], b[25];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  int s = 0;
  for (int i = 0; i < n; i++) s += a[i];
  double res = V;
  for (int i = 0; i < n; i++) res = min(res, 1.0 * b[i] / a[i] * s);
  cout << res << endl;
}
