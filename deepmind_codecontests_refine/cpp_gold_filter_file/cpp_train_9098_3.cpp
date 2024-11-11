#include <bits/stdc++.h>
using namespace std;
int t[300010];
set<int> s;
int main() {
  int n, m, l, r, x;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }
  for (int i = 0; i < m; i++) {
    cin >> l >> r >> x;
    set<int>::iterator it;
    it = s.lower_bound(l);
    vector<int> toErase;
    while (it != s.end()) {
      if (*it == x) {
        it++;
        continue;
      }
      if (*it > r) break;
      toErase.push_back(*it);
      it++;
    }
    for (int j = 0; j < toErase.size(); j++) {
      t[toErase[j]] = x;
      s.erase(toErase[j]);
    }
  }
  cout << t[1];
  for (int i = 2; i <= n; i++) {
    cout << " " << t[i];
  }
  cout << endl;
  return 0;
}
