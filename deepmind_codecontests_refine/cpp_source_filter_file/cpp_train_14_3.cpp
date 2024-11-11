#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int n, u, v;
int a[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    a[u]++;
    a[v]++;
  }
  int cnt[3] = {0, 0, 0};
  for (int i = 1; i <= n; i++) {
    if (a[i] <= 2) cnt[a[i]]++;
  }
  if (cnt[2] == 0 && cnt[1] * (cnt[1] - 1) / 2 >= n - 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
