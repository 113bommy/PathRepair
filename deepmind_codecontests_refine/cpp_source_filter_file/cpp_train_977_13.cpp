#include <bits/stdc++.h>
using namespace std;
const int N = 10110;
int n;
int a[N], s[N], f[N];
void update(int x, int v) {
  for (; x <= n; x += x & -x) s[x] = max(s[x], v);
}
int cal(int x) {
  int r = 0;
  for (; x > 0; x -= x & -x) r = max(r, s[x]);
  return r;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int r = 0;
  for (int i = 1; i <= n; i++) {
    f[i] = cal(a[i] - 1) + 1;
    update(a[i], f[i]);
    r = max(r, f[i]);
  }
  cout << r << endl;
}
