#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(false);
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> t(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  set<int> d;
  while (q--) {
    int i, id;
    cin >> i >> id;
    if (i == 1) {
      d.insert(t[id]);
    } else {
      if (d.find(t[id]) != d.end()) {
        cout << "YES";
      } else {
        cout << "NO";
      }
      cout << endl;
    }
    while (d.size() > k) {
      d.erase(d.begin());
    }
  }
}
