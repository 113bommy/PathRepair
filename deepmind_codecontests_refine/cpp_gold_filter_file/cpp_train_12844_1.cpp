#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 4 == 2 || n % 4 == 3) {
    cout << "-1\n";
    return 0;
  }
  vector<int> v(n + 1, 0);
  int skip = n + 3;
  if (n % 4 == 1) skip = n / 2 + 1;
  for (int i = 1; i <= n; i += 2) {
    if (i >= skip)
      break;
    else if (v[i] > 0)
      break;
    v[i + 1] = i;
    v[i] = n - i;
    v[n - i] = n - i + 1;
    v[n - i + 1] = i + 1;
  }
  if (skip <= n) v[skip] = skip;
  for (int i = 1; i <= n; i += 1) cout << v[i] << ' ';
  cout << '\n';
  return 0;
}
