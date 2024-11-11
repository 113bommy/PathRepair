#include <bits/stdc++.h>
using namespace std;
char a[100010], b[100010];
int seq[100010], sqi[100010];
vector<int> pos[130];
int main() {
  int n, m;
  scanf("%s%n ", a, &n);
  scanf("%s%n ", b, &m);
  for (int i = 0; i < n; i++) pos[a[i]].push_back(i);
  seq[0] = -1;
  for (int i = 0; i < m; i++) {
    int u = upper_bound(pos[b[i]].begin(), pos[b[i]].end(), seq[i]) -
            pos[b[i]].begin();
    if (u == pos[b[i]].size())
      seq[i + 1] = n;
    else
      seq[i + 1] = pos[b[i]][u];
  }
  sqi[m] = n;
  for (int i = m - 1; i >= 0; i--) {
    int u = lower_bound(pos[b[i]].begin(), pos[b[i]].end(), sqi[i + 1]) -
            pos[b[i]].begin() - 1;
    if (u < 0)
      sqi[i] = -1;
    else
      sqi[i] = pos[b[i]][u];
  }
  int res = 0;
  for (int i = 0; i < m + 1; i++) {
    if (seq[i] == n) break;
    int u = upper_bound(sqi, sqi + m, seq[i]) - sqi;
    res = max(res, m - u + i);
  }
  if (!res) {
    printf("-");
    return 0;
  }
  for (int i = 0; i < m + 1; i++) {
    int u = upper_bound(sqi, sqi + m, seq[i]) - sqi;
    if (m - u + i == res) {
      for (int j = 0; j < i; j++) printf("%c", b[j]);
      for (int j = u; j < m; j++) printf("%c", b[j]);
      return 0;
    }
  }
  return 0;
}
