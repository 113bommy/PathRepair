#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, i, j, c;
  cin >> t;
  for (i = 0; i < n; i++) {
    cin >> n;
    set<int> s1;
    set<int> s2;
    for (j = 0; j < n; j++) {
      cin >> c;
      s1.insert(c);
    }
    for (j = 0; j < n; j++) {
      cin >> c;
      s2.insert(c);
    }
    for (auto k = s1.begin(); k != s1.end(); k++) {
      cout << *k << " ";
    }
    cout << endl;
    for (auto k = s2.begin(); k != s2.end(); k++) {
      cout << *k << " ";
    }
    cout << endl;
  }
  return 0;
}
