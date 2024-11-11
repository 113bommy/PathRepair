#include <bits/stdc++.h>
using namespace std;
struct xx {
  int m, p, v;
} a[110];
bool cmp(xx a, xx b) { return a.v < b.v; }
long long f[1100000];
int main() {
  int n, m, b;
  cin >> n >> m >> b;
  memset(f, -1, sizeof(f));
  f[0] = 0;
  int mx = 1 << m;
  for (int i = 1; i <= n; i++) {
    int p;
    scanf("%d%d%d", &a[i].m, &a[i].v, &p);
    while (p--) {
      int x;
      scanf("%d", &x);
      a[i].p |= 1 << (x - 1);
    }
  }
  sort(a + 1, a + n + 1, cmp);
  long long ans = -1, ans2;
  for (int i = 1; i <= n; i++) {
    ans2 = a[i].v * b;
    for (int j = mx - 1; j >= 0; j--)
      if (f[j] >= 0) {
        int k = j | a[i].p;
        if (f[k] == -1 || f[k] > f[j] + a[i].m) f[k] = f[j] + a[i].m;
      }
    if (f[mx - 1] != -1) {
      if (ans == -1)
        ans = f[mx - 1] + ans2;
      else
        ans = min(ans, f[mx - 1] + ans2);
    }
  }
  cout << ans << endl;
}
