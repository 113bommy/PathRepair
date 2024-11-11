#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, n;
  cin >> t;
  while (t--) {
    cin >> n;
    set<int> p;
    for (int i = 0; i < n; i++) {
      cin >> a;
      p.insert(a);
    }
    cout << (p.size() == 1 ? n : 1);
  }
  return 0;
}
