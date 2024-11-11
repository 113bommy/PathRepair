#include <bits/stdc++.h>
using namespace std;
int const maxn = 300010;
int n;
long long w[maxn];
long long ans[maxn];
long long s[maxn];
struct node {
  int a, id;
  node(int a, int id) : a(a), id(id) {}
  node() {}
  friend bool operator<(node x, node y) { return x.a < y.a; }
};
vector<node> v[551];
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; ++i) {
      scanf("%I64d", &w[i]);
    }
    for (int i = 1; i <= 550; ++i) {
      v[i].clear();
    }
    int m, a, b;
    scanf("%d", &m);
    for (int z = 0; z < m; ++z) {
      scanf("%d%d", &a, &b);
      if (b > 550) {
        long long ret = 0;
        for (int i = a; i <= n; i += b) ret += w[i];
        ans[z] = ret;
      } else {
        v[b].push_back(node(a, z));
      }
    }
    for (int i = 1; i <= 550; ++i) {
      if (v[i].size() != 0) {
        sort(v[i].begin(), v[i].end());
        int pos = v[i].size() - 1;
        memset(s, 0, sizeof s);
        for (int j = n; pos >= 0 && j >= 1; --j) {
          if (j + i > n)
            s[j] = w[j];
          else
            s[j] = s[j + i] + w[j];
          while (j == v[i][pos].a) {
            ans[v[i][pos].id] = s[j];
            --pos;
          }
        }
      }
    }
    for (int i = 0; i < m; ++i) printf("%I64d\n", ans[i]);
  }
  return 0;
}
