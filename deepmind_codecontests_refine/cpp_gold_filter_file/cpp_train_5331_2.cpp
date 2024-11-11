#include <bits/stdc++.h>
using namespace std;
const int N = 105, M = 2e4 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;
int n, m;
int a[N][N], sum[N], tmp[N], mn = 1e9;
vector<int> ans, res;
struct cha {
  int id;
  int x;
  bool operator<(const cha& c) const { return x > c.x; }
} C[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
      sum[j] += a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) tmp[i] = sum[i];
  sort(tmp + 1, tmp + n + 1);
  if (tmp[n] != sum[n] || (tmp[n - 1] == tmp[n])) {
    puts("0");
    puts("");
    return 0;
  }
  for (int goal = 1; goal < n; goal++) {
    int sg = sum[goal], sn = sum[n];
    sn -= sg;
    ans.clear();
    for (int i = 1; i <= m; i++) {
      C[i].x = a[i][n] - a[i][goal];
      C[i].id = i;
    }
    sort(C + 1, C + m + 1);
    int cnt = 0;
    for (int i = 1; C[i].x > 0 && i <= m; i++) {
      sn -= C[i].x;
      cnt++, ans.push_back(C[i].id);
      if (sn <= 0) break;
    }
    if (sn <= 0) {
      if (ans.size() < mn) {
        res = ans;
        mn = ans.size();
      }
    }
  }
  printf("%d\n", mn);
  for (int i : res) printf("%d ", i);
  return 0;
}
