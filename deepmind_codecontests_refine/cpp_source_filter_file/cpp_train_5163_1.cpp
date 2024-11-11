#include <bits/stdc++.h>
using namespace std;
const int N = 345678;
multiset<int> s;
vector<int> g[N];
int a[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s.insert(a[i]);
  }
  int u, v;
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  long long mins = 1e10 + 1;
  for (int i = 1; i <= n; i++) {
    int h;
    int foo = a[i];
    h = foo;
    s.erase(s.find(foo));
    for (int x : g[foo]) {
      h = max(a[x] + 1, h);
      s.erase(s.find(a[x]));
    }
    if (!s.empty()) {
      auto f = s.rbegin();
      h = max(h, *f + 2);
    }
    mins = min(mins, (long long)h);
    for (int x : g[foo]) {
      s.insert(a[x]);
    }
    s.insert(foo);
  }
  printf("%I64d\n", mins);
  return 0;
}
