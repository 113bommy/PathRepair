#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
int t[100005];
int a[100005];
int len;
int lowbit(int x) { return x & -x; }
void add(int pos, int z) {
  for (int i = pos; i < 100005; i += lowbit(i)) {
    t[i] = max(z, t[i]);
  }
}
int qry(int pos) {
  int ans = 0;
  for (int i = pos; i; i -= lowbit(i)) ans = max(ans, t[i]);
  return ans;
}
int f1[100005], f2[100005];
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int s, e;
    cin >> s >> e;
    a[s]++, a[e + 1]--;
  }
  int tmp = 0;
  for (int i = 1; i <= m; i++) {
    tmp += a[i];
    a[i] = tmp + 1;
  }
  for (int i = 1; i <= m; i++) {
    f1[i] = qry(a[i]) + 1;
    add(a[i], f1[i]);
  }
  memset(t, 0, sizeof(t));
  for (int i = m; i >= 1; i--) {
    f2[i] = qry(a[i]) + 1;
    add(a[i], f2[i]);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, f1[i] + f2[i] - 1);
  cout << ans << endl;
  return 0;
}
