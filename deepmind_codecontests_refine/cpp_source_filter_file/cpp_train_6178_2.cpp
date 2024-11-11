#include <bits/stdc++.h>
using namespace std;
int arr[210];
int getZero(int n) {
  for (int i = 1; i < n; i++) {
    if (arr[i] == 0) return i;
  }
  return 0;
}
int getI(int i, int n) {
  for (int j = 1; j <= n; j++) {
    if (arr[j] == i) return j;
  }
  return i;
}
int main() {
  int n, m, c = 0;
  cin >> n >> m;
  for (int i = 1, t, q = 1; i <= m; i++) {
    cin >> t;
    c += t;
    for (int j = 1, k; j <= t; j++, q++) {
      cin >> k;
      arr[k] = q;
    }
  }
  pair<int, int> sol[1000];
  int sz = 0;
  for (int i = 1; i <= c; i++) {
    if (arr[i] != i) {
      int idx = getI(i, n);
      if (arr[i] == 0) {
        sol[sz++] = make_pair(idx, i);
        arr[idx] = 0;
        arr[i] = i;
      } else {
        int z = getZero(n);
        sol[sz++] = make_pair(i, z);
        sol[sz++] = make_pair(idx, i);
        arr[z] = arr[i];
        arr[i] = i;
        arr[idx] = 0;
      }
    }
  }
  cout << sz << endl;
  for (int i = 0; i < sz; i++) {
    cout << sol[i].first << " " << sol[i].second << endl;
  }
  return 0;
}
