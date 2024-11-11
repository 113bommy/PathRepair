#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  int **a = new int *[n];
  for (int i = 0; i < n; ++i) {
    a[i] = new int[m];
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  vector<int> s(n, 0), gr(m, 0);
  for (int i = 0; i < k; ++i) {
    int b1, b2;
    scanf("%d %d", &b1, &b2);
    gr[b2 - 1]++;
    s[b1 - 1]++;
  }
  for (int i = 0; i < n; ++i) {
    int res = 0;
    for (int j = 0; j < m; ++j) {
      res += gr[j] * a[i][j];
    }
    res -= s[i];
    printf("%d ", res);
  }
  return 0;
}
