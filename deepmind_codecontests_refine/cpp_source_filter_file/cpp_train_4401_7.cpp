#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      s.insert(a);
    }
    if ((int)s.size() == n)
      cout << n << endl;
    else
      cout << 1 << endl;
  }
  return 0;
}
