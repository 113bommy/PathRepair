#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t) {
    t--;
    set<int> sets;
    cin >> n;
    int f;
    for (int i = 0; i < n; i++) {
      cin >> f;
      sets.insert(f);
    }
    int res = 0;
    while (!sets.empty()) {
      int m = *sets.rbegin();
      sets.erase(m);
      if (m % 2 == 0) {
        res++;
        sets.insert(m / 2);
      }
    }
    cout << res << '\n';
  }
  return 0;
}
