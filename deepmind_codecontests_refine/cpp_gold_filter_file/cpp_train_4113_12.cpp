#include <bits/stdc++.h>
using namespace std;
const int maxx = 1e6 + 100;
int a[maxx][2], ans[1000];
int main() {
  int n, m;
  cin >> n;
  for (int i = 2; i <= 2 * n; i++)
    for (int j = 1; j < i; j++) cin >> m, a[m][0] = i, a[m][1] = j;
  for (int i = maxx; i > 0; i--)
    if (!ans[a[i][0]] && !ans[a[i][1]])
      ans[a[i][0]] = a[i][1], ans[a[i][1]] = a[i][0];
  for (int i = 1; i <= 2 * n; i++) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}
