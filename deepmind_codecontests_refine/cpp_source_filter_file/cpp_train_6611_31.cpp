#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, b[111111], f[111111], a[111111];
  cin >> n >> m;
  map<int, int> mm, mk;
  for (int i = 1; i <= n; i++) {
    mm[i] = 0;
    mk[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
    mm[f[i]] = i;
    mk[f[i]]++;
  }
  int amb = -1;
  int unr = -1;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    if (mm[b[i]] > 0)
      ;
    a[b[i]] = mm[b[i]];
    if (mk[b[i]] > 1) amb = 1;
    if (mk[b[i]] == 0) unr = 1;
  }
  if (unr == 1) {
    cout << "Impossible";
    return 0;
  }
  if (amb == 1) {
    cout << "Ambiguity";
    return 0;
  }
  cout << "Possible" << endl;
  for (int i = 1; i <= n; i++) cout << mm[i] << " ";
  return 0;
}
