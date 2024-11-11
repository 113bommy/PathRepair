#include <bits/stdc++.h>
using namespace std;
using lld = long long;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  lld n;
  cin >> n;
  vector<pair<lld, int> > t;
  for (lld i = 2; i * i <= n; i++)
    if (n % i == 0) {
      t.push_back({i, 0});
      while (n % i == 0) n /= i, t.back().second++;
    }
  if (n > 1) t.push_back({n, 1});
  if (t.size() >= 2 || t.size() == 0) {
    cout << "0\n";
    return 0;
  }
  lld res = t.back().second;
  cout << res << "\n";
  return 0;
}
