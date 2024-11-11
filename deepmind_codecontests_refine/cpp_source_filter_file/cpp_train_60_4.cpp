#include <bits/stdc++.h>
using namespace std;
int n, ok = 1;
long long a[100005], b[100005];
struct xx {
  int to, k;
  xx(int a, int b) : to(a), k(b){};
};
vector<xx> v[100005];
void dfs(int now) {
  for (int i = 0; i < v[now].size(); i++) {
    int t = v[now][i].to, k = v[now][i].k;
    dfs(t);
    if (a[t] < 0) {
      if (1.0 * a[t] * k + a[now] < -1e-17) ok = 0;
      a[now] += a[t] * k;
    } else
      a[now] += a[t];
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i], a[i] -= b[i];
  for (int i = 2; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(xx(i, y));
  }
  dfs(1);
  if (ok && a[1] >= 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
