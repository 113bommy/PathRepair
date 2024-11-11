#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int maxn = 2e5 + 7;
int n, m, a[maxn];
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i += 1) scanf("%d", a + i);
    int cnt = 2;
    map<int, int> vis;
    for (int i = 2; i <= n; i += 1) {
      vis[a[i]]++;
    }
    for (auto itr : vis) {
      cnt += itr.second - 1;
    }
    printf("%d\n", cnt);
  }
  return 0;
}
