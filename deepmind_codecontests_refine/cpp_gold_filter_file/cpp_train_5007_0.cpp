#include <bits/stdc++.h>
using namespace std;
const double eps = 0.0000000000001;
const long long mod = 4294967296;
const long long M = 1000000000;
int n, m;
vector<int> a[1000005], b[1000005];
bool f[1000005];
bool ff[1000005];
vector<int> ans;
bool find(int x, int t) {
  if (t > 2) return false;
  for (int i = 0; i < b[x].size(); i++) {
    if (f[b[x][i]] == 0)
      return true;
    else {
      t++;
      if (find(b[x][i], t) == true) return true;
    }
  }
  return false;
}
int main() {
  scanf("%d%d", &n, &m);
  int x, y;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    a[x].push_back(y);
    b[y].push_back(x);
  }
  memset(f, 0, sizeof(f));
  memset(ff, 0, sizeof(ff));
  for (int i = 1; i <= n; i++) {
    if (ff[i] == 0) {
      ff[i] = 1;
      f[i] = 1;
      for (int j = 0; j < a[i].size(); j++) {
        ff[a[i][j]] = 1;
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    if (f[i] == 1) {
      for (int j = 0; j < b[i].size(); j++) {
        if (f[b[i][j]] == 1) {
          f[i] = 0;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (f[i] == 1) ans.push_back(i);
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
