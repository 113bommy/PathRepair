#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
int n, m;
char a[maxn], b[maxn];
vector<int> g;
int main() {
  long long ans = 0;
  scanf("%d", &n);
  scanf("%s", a);
  scanf("%s", b);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      if ((int)g.size() > 0 && g[int(g.size() - 1)] == i - 1 &&
          b[g[int(g.size() - 1)]] != b[i])
        continue;
      else
        g.push_back(i);
    }
  }
  printf("%d\n", int(g.size()));
  return 0;
}
