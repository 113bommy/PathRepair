#include <bits/stdc++.h>
using namespace std;
vector<int> v;
set<int> s;
int choice[150005];
int main() {
  std::ios::sync_with_stdio(false);
  int n, k, q, m, ma = 0;
  cin >> n >> k >> q;
  for (int i = 1; i <= n; i++) cin >> choice[i];
  for (int i = 0; i < q; i++) {
    cin >> m >> n;
    if (m == 1) s.insert(choice[n]), ma = max(ma, choice[n]);
    int sz = s.size();
    int mi = min(k, sz);
    set<int>::iterator it = s.end(), it1, it2;
    it1 = s.lower_bound(ma);
    int check = 0;
    if (m == 2 && sz == 0)
      cout << "NO\n";
    else if (m == 2) {
      int j = sz - 1;
      for (it2 = it1; j >= sz - mi; it2--, j--) {
        if (*it2 == choice[n]) {
          check = 1, cout << "YES\n";
          break;
        }
      }
      if (check == 0) cout << "NO\n";
    }
  }
  return 0;
}
