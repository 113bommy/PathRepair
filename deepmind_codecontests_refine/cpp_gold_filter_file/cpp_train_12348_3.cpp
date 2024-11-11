#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, v[205];
  cin >> m;
  n = m * 2;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v, v + n);
  if (v[m] > v[m - 1])
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
