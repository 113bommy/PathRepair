#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, k, c = 0, p[51], t[51];
  pair<int, int> v[51];
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> p[i] >> t[i];
    v[i] = pair<int, int>(-p[i], t[i]);
  }
  sort(v, v + n);
  int pp = v[k - 1].first;
  int tt = v[k - 1].second;
  for (i = n - 1; i >= 0; i--) {
    if (v[i].first == pp && v[i].second == tt) c++;
  }
  cout << c << endl;
  return 0;
}
