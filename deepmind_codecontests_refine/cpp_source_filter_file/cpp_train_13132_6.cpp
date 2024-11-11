#include <bits/stdc++.h>
using namespace std;
int a[30][30] = {};
int m, n;
bool ok(int tt) {
  int i, j;
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++)
      if (((1 << i & tt) > 0) && ((1 << j & tt) > 0)) {
        if (a[i][j] == 1) {
          return 0;
        }
      }
  return 1;
}
int countbit(int tt) {
  int i, c = 0;
  for (i = 0; i < n; i++)
    if (((1 << i) & tt) > 0) c++;
  return c;
}
int main() {
  map<string, int> num;
  string name[15], n1, n2;
  int i, j, k;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> name[i];
    num[name[i]] = i;
  }
  for (i = 0; i < m; i++) {
    cin >> n2 >> n1;
    a[num[n1]][num[n2]] = 1;
    a[num[n2]][num[n1]] = 1;
  }
  int res = 0;
  for (i = 0; i < (1 << n); i++) {
    if (ok(i) && (countbit(i) > countbit(res))) {
      res = i;
    }
  }
  string tmp;
  cout << countbit(res) << "\n";
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++)
      if (((1 << i & res) > 0) && ((1 << i & res) > 0))
        if (name[j] < name[i]) {
          tmp = name[i];
          name[i] = name[j];
          name[j] = tmp;
        }
  for (i = 0; i < n; i++)
    if ((1 << i & res) > 0) cout << name[i] << "\n";
}
