#include <bits/stdc++.h>
using namespace std;
set<int> d;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, n, a, k = 0;
  cin >> t >> n;
  int x[200] = {};
  for (int i = 1; i <= t; ++i) {
    cin >> a;
    if (x[a] >= 1)
      continue;
    else {
      x[a] += 1;
      d.insert(i);
    }
  }
  if (d.size() < n)
    cout << "NO\n";
  else {
    cout << "YES\n";
    for (auto i : d) {
      k += 1;
      cout << i << " ";
      if (k == n) break;
    }
  }
  return 0;
}
