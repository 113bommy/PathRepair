#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005], e[100005], aux[100005] = {0}, mn = INT_MAX;
int main() {
  int n, m, k, x;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) cin >> a[i] >> b[i] >> e[i];
  for (int i = 0; i < k; i++) {
    cin >> x;
    aux[x] = 1;
  }
  for (int i = 0; i < m; i++) {
    if (aux[a[i]] + aux[b[i]] == 1) {
      mn = min(mn, e[i]);
    }
  }
  if (mn == INT_MAX)
    cout << "-1\n";
  else
    cout << mn << "\n";
  return 0;
}
