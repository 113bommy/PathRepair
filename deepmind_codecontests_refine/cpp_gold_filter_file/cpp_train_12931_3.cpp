#include <bits/stdc++.h>
int main() {
  int n, m, queries;
  scanf("%d %d", &n, &m);
  char setN[n][11];
  char setM[m][11];
  for (int i = 0; i < n; i++) scanf("%s", setN[i]);
  for (int i = 0; i < m; i++) scanf("%s", setM[i]);
  scanf("%d", &queries);
  int query[queries];
  for (int i = 0; i < queries; i++) scanf("%d", &query[i]);
  for (int i = 0; i < queries; i++) {
    char name[21] = "";
    int nIndex, mIndex;
    if ((query[i] % n) == 0)
      nIndex = n - 1;
    else
      nIndex = (query[i] % n) - 1;
    if ((query[i] % m) == 0)
      mIndex = m - 1;
    else
      mIndex = (query[i] % m) - 1;
    strcat(name, setN[nIndex]);
    strcat(name, setM[mIndex]);
    printf("%s\n", name);
  }
  return 0;
}
