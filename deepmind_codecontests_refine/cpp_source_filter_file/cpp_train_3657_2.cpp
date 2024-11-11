#include <bits/stdc++.h>
using namespace std;
int Erdos_Gallai(vector<int> d, int a) {
  d.back() = a;
  sort(d.rbegin(), d.rend());
  const int n = d.size();
  vector<int> pre(n + 1, 0);
  for (int i = 0; i < n; ++i) pre[i + 1] += pre[i] + d[i];
  for (int k = 1, j = n; k <= n; ++k) {
    while (k < j and (d[j - 1] <= k)) --j;
    j = max(k, j);
    if (pre[k] >
        (long long)k * (k - 1) + pre[n] - pre[j] + (long long)k * (j - k))
      return a > d[k] ? 1 : -1;
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  vector<int> d;
  cin >> n;
  d.resize(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    d[i] = a;
  }
  int r = n, l = -1;
  while (r - l > 1) {
    int m = r + l >> 1;
    if (Erdos_Gallai(d, m) >= 0)
      r = m;
    else
      l = m;
  }
  int firstNonNegetive = r;
  if (Erdos_Gallai(d, firstNonNegetive)) return cout << -1 << '\n', 0;
  l = r, r = n + 1;
  while (r - l > 1) {
    int m = r + l >> 1;
    if (Erdos_Gallai(d, m) == 0)
      l = m;
    else
      r = m;
  }
  int par = accumulate(d.begin(), d.end() - 1, 0ll) % 2;
  bool hasAns = false;
  for (int i = firstNonNegetive; i < r; ++i) {
    if (i < 0 or i > n or par != i % 2) continue;
    cout << i << ' ', hasAns = 1;
  }
  if (not hasAns)
    cout << "-1\n";
  else
    cout << "\n";
};
