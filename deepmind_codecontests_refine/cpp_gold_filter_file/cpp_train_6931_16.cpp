#include <bits/stdc++.h>
using namespace std;
int n, v[100005], t[100005], k;
vector<int> p[100005];
int main() {
  int i, j, l;
  scanf("%d", &n);
  n++;
  for (i = 2; i <= n; i++) v[i] = i;
  for (i = 2; i <= n; i++) {
    sort(p[i].begin(), p[i].end());
    for (j = 0; j < p[i].size(); j++)
      if (p[i][j] != j + 1) {
        t[i] = j + 1;
        break;
      }
    if (t[i] == 0) {
      if (p[i].size() >= 1)
        t[i] = p[i][p[i].size() - 1] + 1;
      else
        t[i] = 1;
    }
    k = max(k, t[i]);
    if (v[i] != 1)
      for (j = 2 * i; j <= n; j += i) {
        while (v[j] % i == 0) v[j] /= i;
        p[j].push_back(t[i]);
      }
  }
  printf("%d\n", k);
  for (i = 2; i <= n; i++) printf("%d ", t[i]);
  return 0;
}
