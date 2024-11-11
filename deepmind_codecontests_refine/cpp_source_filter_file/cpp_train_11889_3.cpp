#include <bits/stdc++.h>
using namespace std;
struct dot {
  long double x = 0;
  long double y = 0;
};
const double PI = 3.141592653589;
inline void solve() {
  int n;
  cin >> n;
  vector<int> p(n + 1);
  for (int i = 1; i < n + 1; i++) cin >> p[i];
  vector<int> ans(n + 1);
  vector<bool> used(n);
  for (int i = 1; i < n + 1; i++) {
    if (!used[i]) {
      int j = i;
      vector<int> c;
      while (!used[j]) {
        used[j] = 1;
        j = p[j];
        c.push_back(j);
      }
      for (int k = 0; k < (int)(c).size(); k++) {
        ans[c[k]] = (int)(c).size();
      }
    }
  }
  for (int i = 1; i < n + 1; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
int main() {
  cout.precision(9);
  int t;
  cin >> t;
  while (t--) solve();
}
