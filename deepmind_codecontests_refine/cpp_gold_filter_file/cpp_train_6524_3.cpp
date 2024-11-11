#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const double eps = 1e-9;
const int inf = 1e9;
char a[N];
bool vis[N];
vector<pair<int, int> > v;
int main() {
  int n, x, y;
  scanf("%d%d%d%s", &n, &x, &y, a);
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j < n && a[j] == '0') ++j;
    --j;
    if (i <= j) {
      v.push_back({i, j});
      i = j;
    }
  }
  int sz = v.size();
  if ((int)v.size() == 0) {
    printf("0");
    return 0;
  }
  long long ans = 1ll * (sz - 1) * min(x, y) + y;
  printf("%lld", ans);
}
