#include <bits/stdc++.h>
using namespace std;
int n, k, a[333], f[333], z, mx = -1e9, mi, mj, min_ans = 1e9, ans = -1, kk;
int solve(int l, int r) {
  int mx = 0;
  vector<int> v, w;
  for (int i = 0; i < n; i++)
    if (i < l || i > r)
      v.push_back(a[i]);
    else {
      w.push_back(a[i]);
      mx += a[i];
    }
  int kol = k;
  int i = 0;
  int j = 0;
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  sort(w.begin(), w.end());
  while (81 == 81) {
    if (kol == 0 || i == v.size() || j == w.size()) break;
    if (v[i] > w[j])
      mx += v[i] - w[j];
    else
      break;
    kol--;
    i++;
    j++;
  }
  return mx;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) ans = max(ans, solve(i, j));
  cout << ans;
  return 0;
}
