#include <bits/stdc++.h>
using namespace std;
int main() {
  int v, a[10], i, j;
  vector<int> res;
  cin >> v;
  int mn = 1e8, sm = 0;
  for (i = 1; i < 10; i++) {
    cin >> a[i];
    if (a[i] <= mn) {
      mn = a[i];
      sm = i;
    }
  }
  if (v < mn) {
    cout << -1 << endl;
    return 0;
  }
  while (v >= mn) {
    v -= mn;
    res.push_back(sm);
  }
  for (i = 0; i < res.size(); i++) {
    for (j = 9; j > sm; j--) {
      if (a[j] <= v) {
        v -= a[j] - mn;
        res[i] = j;
        break;
      }
    }
  }
  for (i = 0; i < res.size(); i++) printf("%d", res[i]);
  cout << endl;
  return 0;
}
