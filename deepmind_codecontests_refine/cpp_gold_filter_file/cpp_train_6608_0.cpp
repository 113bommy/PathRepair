#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, int> m;
  map<int, int>::iterator it;
  int n;
  int k;
  cin >> n >> k;
  int a[n];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (m.count(j * a[i]))
        m[j * a[i]] = min(m[j * a[i]], j);
      else
        m[j * a[i]] = j;
    }
  }
  m[0] = 0;
  cin >> q;
  while (q--) {
    int x;
    int z = k + 1;
    cin >> x;
    for (it = m.begin(); it != m.end(); ++it)
      if (m.count(x - it->first)) z = min(z, m[x - it->first] + it->second);
    if (z > k)
      cout << -1 << endl;
    else
      cout << z << endl;
  }
  return 0;
}
