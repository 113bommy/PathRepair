#include <bits/stdc++.h>
using namespace std;
const int N = 15e4 + 10;
long long a[N];
bool vis[N];
int main() {
  int n;
  scanf("%d", &n);
  set<pair<long long, int> > se;
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
    se.insert(pair<long long, int>(a[i], i));
  }
  int sz = n;
  while (!se.empty()) {
    pair<long long, int> x = *se.begin();
    if (!se.empty()) {
      se.erase(se.begin());
      pair<long long, int> y = *se.begin();
      if (x.first == y.first) {
        se.erase(se.begin());
        se.insert(pair<long long, int>(y.first * 2, y.second));
        vis[x.second] = true;
        sz--;
        a[y.second] = y.first * 2;
      }
    } else
      break;
  }
  printf("%d\n", sz);
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    printf("%d ", a[i]);
  }
  return 0;
}
