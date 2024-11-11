#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, perm[N], inv[N];
bool visited[N];
int min_f(int m) {
  for (int i = 1;; i++) {
    if (i * (i + 1) / 2 >= m) return i;
  }
  return 0;
}
vector<int> v[N];
int f[N], g[N], previous[N];
int get_lis() {
  int ans = 0;
  for (int i = 1; i <= n; i++) f[i] = n + 1;
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (visited[i]) continue;
    int l = 0, r = n + 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (f[mid] < perm[i])
        l = mid;
      else
        r = mid - 1;
    }
    g[i] = l + 1, ans = max(ans, l + 1);
    if (f[l + 1] > perm[i]) {
      f[l + 1] = perm[i], previous[perm[i]] = f[l];
    }
  }
  return ans;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &perm[i]);
      inv[perm[i]] = i, visited[i] = false;
    }
    int lis = 0, cnt = 0, size = n;
    while (size) {
      lis = get_lis();
      if (lis < min_f(size)) {
        for (int i = 1; i <= n; i++) {
          if (!visited[i]) v[cnt + g[i]].push_back(perm[i]);
        }
        cnt += lis, size = 0;
      } else {
        cnt++;
        for (int u = f[lis]; u; u = previous[u]) {
          v[cnt].push_back(u);
          visited[inv[u]] = true, size--;
        }
        reverse(v[cnt].begin(), v[cnt].end());
      }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) {
      printf("%d ", (int)v[i].size());
      for (int j = 0; j < v[i].size(); j++) printf("%d ", v[i][j]);
      printf("\n");
      v[i].clear();
    }
  }
  return 0;
}
