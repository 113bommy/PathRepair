#include <bits/stdc++.h>
using namespace std;
map<int, int> ms;
int m[100005];
int a[100005];
int b[100005];
int u[100005];
int n;
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
  }
  for (int i = 1; i <= n; ++i) {
    b[n + i] = b[i];
  }
  for (int i = 1; i <= n; ++i) {
    u[b[i]] = i;
    m[a[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    ++ms[i - u[a[i]]];
  }
  for (int l = 1; l <= n; ++l) {
    int r = l + n - 1, v = n;
    auto it = ms.lower_bound(1 - l);
    if (it != ms.end()) {
      v = min(v, abs(it->first + l - 1));
    }
    if (it != ms.begin()) {
      v = min(v, abs((--it)->first + l - 1));
    }
    printf("%d\n", v);
    if (--ms[m[b[r + 1]] - u[b[r + 1]]] == 0) {
      ms.erase(m[b[r + 1]] - u[b[r + 1]]);
    }
    u[b[r + 1]] = r + 1;
    ++ms[m[b[r + 1]] - u[b[r + 1]]];
  }
}
int main() {
  int tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}
