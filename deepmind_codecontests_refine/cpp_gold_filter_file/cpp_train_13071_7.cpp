#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N];
bool vis[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long ans = a[n - 1];
  for (int i = 0; i < n; i++)
    if (!vis[a[i]]) {
      long long tmp = 0;
      for (long long j = a[i]; j <= a[n - 1]; j += a[i])
        vis[j] = true,
        tmp += j * (lower_bound(a, a + n, j + a[i]) - lower_bound(a, a + n, j));
      if (tmp > ans) ans = tmp;
    }
  cout << ans << endl;
  return 0;
}
