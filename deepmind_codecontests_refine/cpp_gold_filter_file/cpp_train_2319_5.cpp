#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 3e5 + 5;
int t, n, a[N];
int lst[N], mx[N];
vector<int> g[N];
int get(int mid) {
  int x = 2e9;
  for (int i = 1; i <= mid; i++)
    for (auto &j : g[i]) x = min(x, j);
  if (x == 2e9) x = -1;
  return x;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) mx[i] = 0, lst[i] = -1, g[i].clear();
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mx[a[i]] = max(mx[a[i]], i - lst[a[i]]);
      lst[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
      mx[a[i]] = max(mx[a[i]], n - lst[a[i]]);
      g[mx[a[i]]].push_back(a[i]);
    }
    int low = 1, high = n, mid, j = -1;
    while (low <= high) {
      mid = low + high >> 1;
      if (get(mid) != -1)
        j = mid, high = mid - 1;
      else
        low = mid + 1;
    }
    if (j == -1) {
      for (int i = 0; i < n; i++) cout << "-1 ";
      cout << '\n';
      continue;
    }
    int x = get(j);
    for (int i = 1; i < j; i++) cout << "-1 ";
    for (int i = j; i <= n; i++) {
      cout << x << " ";
      if (i + 1 <= n)
        for (auto &k : g[i + 1]) x = min(x, k);
    }
    cout << '\n';
  }
  return 0;
}
