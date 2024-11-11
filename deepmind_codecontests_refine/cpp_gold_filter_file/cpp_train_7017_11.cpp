#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
int n, m, a[MAX], mn = 100000003, mni;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int r, s, t;
    scanf("%d%d%d", &r, &s, &t);
    if (!a[r] && !a[s] && !a[t])
      a[r] = 1, a[s] = 2, a[t] = 3;
    else if (a[r]) {
      (a[r] == 1) ? (a[s] = 2, a[t] = 3)
                  : ((a[r] == 2) ? (a[s] = 1, a[t] = 3) : (a[s] = 1, a[t] = 2));
    } else if (a[s]) {
      (a[s] == 1) ? (a[r] = 2, a[t] = 3)
                  : ((a[s] == 2) ? (a[r] = 1, a[t] = 3) : (a[r] = 1, a[t] = 2));
    } else if (a[t]) {
      (a[t] == 1) ? (a[s] = 2, a[r] = 3)
                  : ((a[t] == 2) ? (a[s] = 1, a[r] = 3) : (a[s] = 1, a[r] = 2));
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i + 1]);
  }
  return 0;
}
