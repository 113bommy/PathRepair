#include <bits/stdc++.h>
using namespace std;
int n;
int v[4000], d[4000], p[4000];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d %d %d", &v[i], &d[i], &p[i]);
  vector<int> ans;
  for (int idx = 0; idx < n; ++idx) {
    if (p[idx] < 0) continue;
    if (p[idx] >= 0) ans.push_back(idx + 1);
    long long decv = v[idx];
    long long decd = 0;
    for (int i = idx + 1; i < n; ++i) {
      if (p[i] < 0) continue;
      p[i] -= (decv + decd);
      if (p[i] < 0) decd += d[i];
      if (decv != 0) --decv;
    }
  }
  printf("%d\n", ans.size());
  for (auto a : ans) printf("%d ", a);
  return 0;
}
