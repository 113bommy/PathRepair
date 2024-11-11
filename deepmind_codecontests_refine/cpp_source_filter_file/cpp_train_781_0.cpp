#include <bits/stdc++.h>
using namespace std;
int n, k, q, type, id;
vector<int> t;
set<int> s;
int main() {
  cin >> n >> k >> q;
  t.resize(n);
  for (int i = 0; i < n; i++) cin >> t[i];
  for (int i = 0; i < q; i++) {
    cin >> type >> id;
    id--;
    if (type == 1) {
      s.insert(t[id]);
      if (s.size() > k) s.erase(s.begin());
    } else
      cout << (binary_search(s.begin(), s.end(), t[id]) ? "YES" : "NO");
  }
  return 0;
}
