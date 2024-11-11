#include <bits/stdc++.h>
using namespace std;
int a[100005], ans[100005];
int main() {
  ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  n = unique(a + 1, a + n + 1) - a - 1;
  for (int i = 1; i <= n; ++i) ans[a[i]]++;
  for (int i = 2; i < n; ++i)
    if (a[i - 1] == a[i + 1]) ans[a[i]] += 2;
  int best = 1;
  for (int i = 2; i <= k; ++i)
    if (ans[i] > ans[best]) best = i;
  cout << best;
}
