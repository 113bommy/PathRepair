#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 333;
const long long linf = 1e18 + 333;
const int N = 1e6 + 5;
int n, k;
int h[N], s[N], min1[N], min2[N], op[N << 1], cl[N << 1];
vector<int> vec, vals, v[N], cave[N];
void dfs(int p = -1, int x = 1, int m1 = -1, int m2 = -1) {
  if (m1 == -1 or h[x] < h[m1]) {
    m2 = m1;
    m1 = x;
  } else if (m2 == -1 or h[x] < h[m2])
    m2 = x;
  min1[x] = m1;
  min2[x] = m2;
  cave[m1].push_back(x);
  for (__typeof((v[x]).begin()) it = (v[x]).begin(); it != (v[x]).end(); it++) {
    int u = *it;
    if (u != p) dfs(x, u, m1, m2);
  }
}
void up(int x, int add_op, int add_cl) {
  x += N;
  op[x] += add_op;
  cl[x] += add_cl;
  while (x > 1) {
    x >>= 1;
    int mn = min(op[x + x], cl[x + x + 1]);
    op[x] = op[x + x] + op[x + x + 1] - mn;
    cl[x] = cl[x + x] + cl[x + x + 1] - mn;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", h + i);
    vals.push_back(h[i]);
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs();
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d", s + i);
    vals.push_back(s[i]);
  }
  sort(vals.begin(), vals.end());
  vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
  for (int i = 1; i <= n; i++)
    h[i] = lower_bound(vals.begin(), vals.end(), h[i]) - vals.begin();
  for (int i = 1; i <= k; i++)
    s[i] = lower_bound(vals.begin(), vals.end(), s[i]) - vals.begin();
  for (int i = 1; i <= k; i++) {
    up(s[i], 1, 0);
  }
  for (int i = 1; i <= n; i++) {
    vec.push_back(h[min1[i]]);
    up(h[min1[i]] + 1, 0, 1);
  }
  sort(s + 1, s + k + 1);
  sort(vec.begin(), vec.end());
  int need = -1, j = vec.size() - 1;
  for (int i = k; i >= 1; i--) {
    if (vec[j] >= s[i])
      j--;
    else {
      need = s[i];
      break;
    }
  }
  if (need == -1) {
    puts("0");
    return 0;
  }
  int ans = inf;
  for (int i = 1; i <= n; i++) {
    for (__typeof((cave[i]).begin()) it = (cave[i]).begin();
         it != (cave[i]).end(); it++) {
      int x = *it;
      up(h[min1[x]] + 1, 0, -1);
    }
    for (__typeof((cave[i]).begin()) it = (cave[i]).begin();
         it != (cave[i]).end(); it++) {
      int x = *it;
      up(min(need, (min2[x] == -1 ? inf : h[min2[x]])) + 1, 0, 1);
    }
    if (op[1] == 0) {
      ans = min(ans, vals[need] - vals[h[i]]);
    }
    for (__typeof((cave[i]).begin()) it = (cave[i]).begin();
         it != (cave[i]).end(); it++) {
      int x = *it;
      up(min(need, (min2[x] == -1 ? inf : h[min2[x]])) + 1, 0, -1);
    }
    for (__typeof((cave[i]).begin()) it = (cave[i]).begin();
         it != (cave[i]).end(); it++) {
      int x = *it;
      up(h[min1[x]] + 1, 0, 1);
    }
  }
  printf("%d\n", ans == inf ? -1 : ans);
  return 0;
}
