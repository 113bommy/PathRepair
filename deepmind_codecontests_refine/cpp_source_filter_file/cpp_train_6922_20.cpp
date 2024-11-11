#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int na, nb;
  cin >> na >> nb;
  int k, m;
  cin >> k >> m;
  long long a[na], b[nb];
  for (int i = 0; i < na; i++) cin >> a[i];
  for (int i = 0; i < nb; i++) cin >> b[i];
  sort(b, b + nb, greater<int>());
  if (a[k] < b[m]) {
    cout << "YES\n";
  } else
    cout << "NO\n";
  return 0;
}
