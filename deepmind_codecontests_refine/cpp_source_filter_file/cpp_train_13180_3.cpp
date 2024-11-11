#include <bits/stdc++.h>
using namespace std;
int l[10100];
int r[10100];
int per[100100];
int pr(int x) {
  if (x == per[x]) return x;
  return per[x] = pr(per[x]);
}
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int t = 0;
  for (int i = 1; i <= n; i++) {
    per[i] = i;
    cin >> l[i];
    cin >> r[i];
    t += l[i] == 0;
  }
  for (int i = 1; i <= n; i++) {
    if (l[i]) {
      r[l[i]] = i;
      per[pr(i)] = pr(l[i]);
    }
    if (r[i]) {
      l[r[i]] = i;
      per[pr(i)] = pr(r[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (l[i] == 0) {
      if (t == 1) continue;
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        if (pr(i) == pr(j)) continue;
        if (r[j] == 0) {
          r[j] = i;
          l[i] = j;
          per[pr(i)] = pr(j);
          break;
        }
      }
      t--;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << l[i] << " " << r[i] << "\n";
  }
  return 0;
}
