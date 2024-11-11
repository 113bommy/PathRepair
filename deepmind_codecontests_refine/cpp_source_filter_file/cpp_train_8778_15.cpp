#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, temp, max, n, m, pos, mt, add, tot;
  cin >> n >> m;
  int a[m], b[m];
  for (i = 0; i < m; i++) cin >> a[i] >> b[i];
  for (i = 0; i < m; i++) {
    if (tot < n) {
      max = b[i];
      pos = i;
      for (j = i + 1; j < m; j++) {
        if (max < b[j]) {
          max = b[j];
          pos = j;
        }
      }
      b[pos] = b[i];
      b[i] = max;
      temp = a[pos];
      a[pos] = a[i];
      a[i] = temp;
      add = n - tot > a[pos] ? a[pos] : n - tot;
      tot += add;
      mt += b[i] * add;
    } else {
      cout << mt;
      return 0;
    }
  }
  cout << mt;
  return 0;
}
