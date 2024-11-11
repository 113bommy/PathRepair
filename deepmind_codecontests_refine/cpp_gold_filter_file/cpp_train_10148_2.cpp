#include <bits/stdc++.h>
using namespace std;
int n, m, k, a;
long long ct;
int ord[600100], id[600100];
int taps(int a) { return (a + k - 1) / k; }
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> ord[i];
    id[ord[i]] = i;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> a;
    ct += 1ll * taps(id[a]);
    if (id[a] != 1) {
      int prev = ord[id[a] - 1];
      swap(ord[id[a]], ord[id[a] - 1]);
      id[a]--;
      id[prev]++;
    }
  }
  cout << ct;
  return 0;
}
