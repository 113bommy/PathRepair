#include <bits/stdc++.h>
using namespace std;
void fail(string s) {
  cout << s;
  exit(0);
}
void fail(int s) {
  cout << s;
  exit(0);
}
int n;
int x[5005], y[5005];
int d[5005];
vector<int> v[5005];
int len(int a, int b) { return abs(x[a] - x[b]) + abs(y[a] - y[b]); }
int ok = 0;
void dfs(int u, int dep, int mid) {
  d[u] = dep;
  for (int i = (0); i < (n); i++)
    if (len(u, i) > mid) {
      if (!d[i])
        dfs(i, dep + 1, mid);
      else if (d[i] > 0) {
        if ((d[i] - d[u]) % 2 == 0) ok = 1;
      }
    }
  d[u] = -1;
}
int chk(int num) {
  ok = 0;
  for (int i = (0); i < (n); i++) d[i] = 0;
  int ans = 1;
  for (int i = (0); i < (n); i++) {
    if (!d[i]) {
      ans = ans * 2 % 1000000007;
      dfs(i, 1, num);
      if (ok) return 0;
    }
  }
  return ans;
}
signed main() {
  cin >> n;
  for (int i = (0); i < (n); i++) {
    cin >> x[i] >> y[i];
  }
  int ans = -1, can = 0;
  int l = 0, r = 1000000, mid;
  while (l < r) {
    int mid = (l + r) / 2;
    int p = chk(mid);
    if (p)
      ans = mid, can = p, r = mid;
    else
      l = mid + 1;
  }
  cout << ans << '\n' << can << '\n';
  return 0;
}
