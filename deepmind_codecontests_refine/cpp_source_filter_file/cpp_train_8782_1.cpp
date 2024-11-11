#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, i, minimal;
  cin >> m;
  vector<int> sk(m);
  unsigned long long ans = 0;
  for (i = 0; i < m; ++i) cin >> sk[i];
  minimal = *(min(sk.begin(), sk.end()));
  cin >> n;
  vector<int> tov(n);
  for (i = 0; i < n; ++i) cin >> tov[i];
  sort(tov.begin(), tov.end(), std::greater_equal<int>());
  int t = 0;
  for (i = 0; i < n; ++i) {
    t++;
    ans = ans + tov[i];
    if (t % minimal == 0) i += 2;
  }
  cout << ans;
  return 0;
}
