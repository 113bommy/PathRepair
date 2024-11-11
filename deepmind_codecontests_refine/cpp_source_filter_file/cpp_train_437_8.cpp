#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    unordered_set<int> s;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      s.insert(x);
    }
    cout << s.size();
  }
  return 0;
}
