#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int fa[maxn];
int chk(int x) { return x - (x & -x); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  int lim = max((n - 3) / 2, 0);
  if ((k > lim) || (n % 2 == 0) || (n == 9 && k == 2) ||
      (chk(n + 1) == 0 && k == 1) || (chk(n + 1) != 0 && k == 0))
    cout << "NO\n", exit(0);
  cout << "YES\n";
  int num = 2 * max(0, k - 1);
  for (int i = 1; i < num; i += 2) fa[i + 1] = i, fa[i] = max(0, i - 2);
  for (int i = 1; i <= n - num; ++i) {
    if (i == 1)
      fa[i + num] = max(0, num - 1);
    else
      fa[i + num] = (i >> 1) + num;
  }
  if (chk(n - num + 1) && k) fa[n - 1] = fa[n] = 2;
  for (int i = 1; i <= n; ++i) cout << fa[i] << ' ';
  return 0;
}
