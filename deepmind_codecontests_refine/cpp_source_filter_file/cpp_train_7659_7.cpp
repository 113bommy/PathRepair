#include <bits/stdc++.h>
using namespace std;
int v[100100], u[100100], a[100100];
long long d[100100];
vector<int> m[100100];
bool cmp(int i, int j) { return d[i] > d[j]; }
void dfs(int i, int p) {
  int j;
  u[i] = 1;
  if (!v[i]) {
    d[i] = 0;
    return;
  }
  for (j = 0; j < m[i].size(); j++) {
    if (!u[m[i][j]]) dfs(m[i][j], i);
  }
  sort(m[i].begin(), m[i].end(), cmp);
  d[i]++;
  v[i]--;
  for (j = 0; j < m[i].size() && v[i]; j++) {
    if (m[i][j] != p) {
      d[i] += d[m[i][j]];
      d[i]++;
      v[i]--;
    }
  }
  for (j = 0; j < m[i].size() && v[i]; j++) {
    if (v[m[i][j]] && m[i][j] != p) {
      if (v[m[i][j]] < v[i]) {
        d[i] += v[m[i][j]];
        v[i] -= v[m[i][j]];
        v[m[i][j]] = 0;
      } else {
        d[i] += v[i];
        v[m[i][j]] -= v[i];
        v[i] = 0;
      }
    }
  }
}
int main() {
  int i, j, k, n;
  scanf("%d", &n);
  for (i = 0; i < n; scanf("%d", &v[i]), i++)
    ;
  for (k = n - 1; k--;
       scanf("%d%d", &i, &j), i--, j--, m[i].push_back(j), m[j].push_back(i))
    ;
  scanf("%d", &k);
  k--;
  if (!v[k])
    printf("0\n");
  else {
    v[k]++;
    dfs(k, -1);
    printf("%lld\n", d[k] - 1);
  }
  return 0;
}
