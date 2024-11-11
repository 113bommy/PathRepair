#include <bits/stdc++.h>
const int N = (int)1e5 + 228;
using namespace std;
int n, m, k, a[N], b[N];
set<pair<int, int> > st;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  if (n > m) {
    cout << "YES" << endl;
    return 0;
  }
  for (int i = 0; i < n; i++)
    if (a[n - i] > b[n - i]) {
      cout << "YES" << endl;
      return 0;
    }
  cout << "NO" << endl;
  return 0;
}
