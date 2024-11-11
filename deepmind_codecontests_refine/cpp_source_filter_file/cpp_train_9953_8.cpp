#include <bits/stdc++.h>
using namespace std;
int const N = 200001;
int n, p[N], v[N];
vector<int> g[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", v + i);
    p[v[i]] = i;
    g[v[i]].push_back(i);
  }
  long long an = 0, ad = 1;
  int p = 0, cp = 0;
  for (int i = 1; i <= N; ++i) {
    for (auto j : g[i]) {
      if (j > cp)
        an += ad, p = max(p, j);
      else
        an += ad + 1, p = max(p, p + n);
    }
    if (p > n) p -= n, ++ad;
    cp = p;
  }
  printf("%lld\n", an);
}
