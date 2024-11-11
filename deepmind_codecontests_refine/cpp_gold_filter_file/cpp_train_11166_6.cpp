#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int t, fa[100005], vis[100005];
int find(int a) {
  int r = a;
  while (fa[r] != r) r = fa[r];
  return r;
}
void join(int a, int b) {
  int faa = find(a);
  int fbb = find(b);
  if (faa < fbb)
    fa[fbb] = faa;
  else
    fa[faa] = fbb;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= 30; i++) fa[i] = i;
    string j, k;
    cin >> j >> k;
    int ans = 0, flag = 0;
    for (int i = 0; i <= n - 1; i++) {
      int a = j[i] - 'a' + 1, b = k[i] - 'a' + 1;
      if (a > b) {
        flag = 1;
        break;
      }
      if (find(a) != find(b)) {
        ans++;
        join(a, b);
      }
    }
    if (flag == 1) {
      cout << -1 << endl;
      continue;
    }
    cout << ans << endl;
  }
}
