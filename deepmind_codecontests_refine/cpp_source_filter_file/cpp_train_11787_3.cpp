#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  set<long long> x;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    x.insert(a[i]);
  }
  sort(a.begin(), a.end());
  int ans = 0;
  while (!x.empty()) {
    int y = *(x.begin());
    x.erase(y);
    x.erase(y + 1);
    x.erase(y + 2);
    ans++;
  }
  cout << ans << " ";
  ans = 0;
  for (int i = 1; i <= n; i++) {
    int yy = a[i];
    if (x.find(yy - 1) == x.end()) {
      x.insert(yy - 1);
      continue;
    }
    if (x.find(yy) == x.end()) {
      x.insert(yy);
      continue;
    }
    x.insert(yy + 1);
  }
  cout << x.size();
  return 0;
}
