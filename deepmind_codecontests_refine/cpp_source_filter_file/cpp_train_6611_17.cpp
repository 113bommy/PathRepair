#include <bits/stdc++.h>
using namespace std;
long long n, t, m, f[100005], a[100005], b[100005], ind[100005];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
    if (ind[f[i]] == 0)
      ind[f[i]] = i;
    else
      ind[f[i]] = -1;
  }
  for (int i = 1; i <= m; i++) cin >> b[i];
  for (int i = 1; i <= m; i++) {
    if (!ind[b[i]]) {
      cout << "Impossible\n";
      return 0;
    }
    if (ind[b[i]] == -1) t = 1;
    a[i] = ind[b[i]];
  }
  if (t) {
    cout << "Ambiguity\n";
    return 0;
  }
  cout << "Possible\n";
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  cout << endl;
  return 0;
}
