#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const int N = 105;
const int M = 2e3 + 5;
pair<int, int> b[N];
int a[N], ans[N];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", &b[i].first);
      b[i].second = i;
    }
    sort(b, b + n);
    sort(a, a + n, greater<int>());
    for (int i = 0; i < n; ++i) {
      ans[b[i].second] = a[i];
    }
    for (int i = 0; i < n; ++i) {
      printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
    }
  }
  return 0;
}
