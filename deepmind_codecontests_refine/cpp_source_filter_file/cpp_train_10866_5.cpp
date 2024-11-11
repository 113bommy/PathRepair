#include <bits/stdc++.h>
using namespace std;
int a[100005], l[100005], r[100005];
int main() {
  int n, m, i, j, x, y, pos;
  cin >> n >> m;
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  l[1] = r[1] = 0;
  for (i = 2; i <= n; i++) {
    l[i] = l[i - 1];
    if (a[i - 1] > a[i]) l[i]++;
    r[i] = r[i - 1];
    if (a[i - 1] < a[i]) r[i]++;
  }
  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    if (r[x] == r[y] || l[x] == l[y])
      cout << "Yes" << endl;
    else {
      pos = int(upper_bound(l + 1, l + n + 1, l[x]) - l);
      pos--;
      if (l[pos] == l[1] && r[pos] == r[y])
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
  return 0;
}
