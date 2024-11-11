#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int p;
    cin >> p;
    multimap<int, int> m;
    for (int i = 2; i <= p; i++) {
      auto it = m.find(p % i);
      if (it == m.end())
        m.insert({p % i, i});
      else {
        cout << it->second << " " << i << endl;
        break;
      }
    }
  }
}
