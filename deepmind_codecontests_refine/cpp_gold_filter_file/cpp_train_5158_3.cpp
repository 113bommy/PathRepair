#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  long long ans = 0;
  cin >> n >> m;
  int min_ = min(n, m);
  int max_ = max(n, m);
  for (int i = 1; i <= min_; i++) ans += (long long)(i + max_) / 5 - (i / 5);
  cout << ans << endl;
  return 0;
}
