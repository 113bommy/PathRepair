#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
const int inf = 0x3f3f3f3f;
vector<int> ans[MAX];
int res[MAX], C[MAX], a[MAX];
int n, m;
int lowbit(int x) { return x & -x; }
void modify(int x, int val) {
  for (int i = x; i <= n; i += lowbit(i)) C[i] += val;
}
int sum(int x) {
  int res = 0;
  for (int i = x; i; i -= lowbit(i)) res += C[i];
  return res;
}
struct Query {
  int L, R, id;
  bool operator<(const Query rhs) const { return R < rhs.R; }
} v[MAX];
int main() {
  int x;
  while (scanf("%d %d", &n, &m) == 2) {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) {
      scanf("%d %d", &v[i].L, &v[i].R);
      v[i].id = i;
    }
    sort(v, v + m);
    int j = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] <= n) {
        int vv = a[i];
        ans[vv].push_back(i);
        int Size = (int)ans[vv].size();
        if (Size >= vv) {
          modify(ans[vv][Size - vv], 1);
          if (Size > vv) modify(ans[vv][Size - vv - 1], -2);
          if (Size > vv + 1) modify(ans[vv][Size - vv - 1], 1);
        }
      }
      while (j < m && v[j].R == i) {
        res[v[j].id] = sum(v[j].R) - sum(v[j].L - 1);
        j++;
      }
    }
    for (int i = 0; i < m; i++) printf("%d\n", res[i]);
  }
  return 0;
}
