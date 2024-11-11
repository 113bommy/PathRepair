#include <bits/stdc++.h>
using namespace std;
int Lucky[1024], size;
void dfs(int r, int val) {
  if (val) Lucky[size++] = val;
  if (r == 9) {
    return;
  }
  dfs(r + 1, val * 10 + 4);
  dfs(r + 1, val * 10 + 7);
}
bool isLucky(int x) {
  while (x) {
    if (x % 10 != 4 && x % 10 != 7) return false;
    x /= 10;
  }
  return true;
}
int sum[13];
int res(int x, int p) {
  if (x == 0) return p + 1;
  int t = x / sum[p];
  if (t * sum[p] == x) return t;
  return t + 1;
}
void init() {
  size = 0;
  dfs(0, 0);
  sort(Lucky, Lucky + size);
  sum[0] = 1;
  sum[1] = 1;
  for (int i = 2; i <= 12; i++) sum[i] = sum[i - 1] * i;
}
vector<int>::iterator it;
int main() {
  init();
  int n, k, len, po, ans;
  while (scanf("%d%d", &n, &k) != EOF) {
    ans = 0;
    bool flag = true;
    for (len = 1; len <= 12; len++) {
      if (sum[len] >= k) break;
    }
    po = n - len;
    if (po < 0) {
      flag = false;
      printf("-1\n");
      continue;
    }
    ans = upper_bound(Lucky, Lucky + size, po) - Lucky;
    vector<int> ind;
    for (int i = po + 1; i <= n; i++) {
      ind.push_back(i);
    }
    len--;
    for (int i = po + 1; i <= n; i++, len--) {
      int tmp = k / sum[len];
      it = ind.begin() + res(k, len) - 1;
      k -= tmp * sum[len];
      tmp = *it;
      if (isLucky(tmp) && isLucky(i)) ans++;
      ind.erase(it);
    }
    printf("%d\n", ans);
  }
  return 0;
}
