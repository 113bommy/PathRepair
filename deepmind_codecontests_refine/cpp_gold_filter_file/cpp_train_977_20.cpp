#include <bits/stdc++.h>
using namespace std;
const int MAX = 100010;
int n, a[MAX], f[MAX], d[MAX];
long long result;
void update(int x, int val) {
  int u = x;
  while (u <= n) {
    f[u] = max(f[u], val);
    u += (u & -u);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  result = 0;
  int u;
  memset(d, 0, sizeof(d));
  memset(f, 0, sizeof(f));
  d[1] = 1;
  update(a[1], 1);
  int result;
  for (int i = 2; i <= n; i++) {
    u = a[i] - 1;
    result = 0;
    while (u > 0) {
      result = max(result, f[u]);
      u -= (u & -u);
    }
    d[i] = result + 1;
    update(a[i], d[i]);
  }
  result = 0;
  for (int i = 1; i <= n; i++) result = max(result, d[i]);
  cout << result << endl;
}
