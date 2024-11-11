#include <bits/stdc++.h>
using namespace std;
using INT = long long;
const int NN = 272727;
int a[NN], id[NN], b[NN];
bool cmp(int u, int v) { return a[u] < a[v]; }
int B[NN];
void update(int u) {
  for (u; u < NN; u += u & -u) B[u]++;
}
int calc(int u) {
  int ans = 0;
  for (; u; u -= u & -u) ans += B[u];
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i), id[i] = i, b[i] = a[i];
  sort(b + 1, b + n + 1);
  int cnt = unique(b + 1, b + n + 1) - b - 1;
  INT ans = 0;
  sort(id + 1, id + n + 1, cmp);
  int st = 0;
  for (int i = 1; i <= n; i++) {
    int u = id[i];
    for (int j = st + 1; j <= min(n, a[u]); j++) {
      int it = lower_bound(b + 1, b + n + 1, a[j]) - b;
      update(it);
    }
    st = min(n, a[u]);
    int it = lower_bound(b + 1, b + n + 1, a[u]) - b;
    ans += calc(n) - calc(it - 1);
    if (a[u] >= u) ans--;
  }
  cout << ans << endl;
  return 0;
}
