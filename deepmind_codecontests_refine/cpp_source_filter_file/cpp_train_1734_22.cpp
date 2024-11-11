#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010];
vector<int> tmp, ans;
void dfs(int x, int n) {
  ;
  if (x > 18) return;
  if (!a[n]) {
    if (tmp.size() < ans.size()) ans = tmp;
    return;
  }
  int i;
  vector<int> v;
  v.resize(n + 1);
  for (i = 1; i <= n; i++) v[i] = a[i];
  bool flag = 1;
  for (i = 1; i <= n; i++) {
    if (a[i] & 1) {
      flag = 0;
      break;
    }
  }
  if (!flag) {
    for (i = 1; i <= n; i++) {
      if (a[i] & 1) a[i]++;
    }
    tmp.push_back(-(1 << x));
    for (i = 1; i <= n; i++) a[i] >>= 1;
    int nn = unique(a + 1, a + 1 + n) - a - 1;
    dfs(x + 1, nn);
    tmp.pop_back();
    for (i = 1; i <= n; i++) a[i] = v[i];
    for (i = 1; i <= n; i++) {
      if (a[i] & 1) a[i]--;
    }
    tmp.push_back(1 << x);
    for (i = 1; i <= n; i++) a[i] >>= 1;
    nn = unique(a + 1, a + 1 + n) - a - 1;
    dfs(x + 1, nn);
    tmp.pop_back();
    for (i = 1; i <= n; i++) a[i] = v[i];
  } else {
    for (i = 1; i <= n; i++) a[i] >>= 1;
    int nn = unique(a + 1, a + 1 + n) - a - 1;
    dfs(x + 1, nn);
    for (i = 1; i <= n; i++) a[i] = v[i];
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int i;
  for (i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  ans.resize(100);
  dfs(0, n);
  cout << ans.size() << '\n';
  for (i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}
