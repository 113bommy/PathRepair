#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> fig[110];
long long p[110];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> fig[i].second >> fig[i].first;
  }
  sort(fig + 1, fig + n + 1);
  int t;
  cin >> t;
  p[0] = 0;
  p[t + 1] = 1e16;
  for (int i = 1; i <= t; i++) {
    cin >> p[i];
  }
  for (int i = t; i >= 1; i--) {
    p[i] -= p[i - 1];
  }
  long long type = 1, step = 1;
  long long ans = 0;
  while (type <= n) {
    if (fig[type].second <= p[step]) {
      ans += fig[type].second * fig[type].first * step;
      p[step] -= fig[type].second;
      type++;
      continue;
    }
    ans += p[step] * fig[type].first * step;
    fig[type].second -= p[step];
    step++;
  }
  cout << ans << endl;
  return 0;
}
