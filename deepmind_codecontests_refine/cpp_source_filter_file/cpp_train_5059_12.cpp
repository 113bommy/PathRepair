#include <bits/stdc++.h>
using namespace std;
int main() {
  int p, x, y;
  cin >> p >> x >> y;
  for (int i = y; i <= x; i += 50) {
    int t = ((i / 50) % 475);
    set<int> tr;
    for (int j = 0; j < 25; j++) {
      t = (t * 96 + 42) % 475;
      tr.insert(26 + t);
    }
    if (tr.find(p) != tr.end()) {
      cout << "0\n" << '\n';
      return 0;
    }
  }
  for (int i = x;; i += 50) {
    int t = ((i / 50) % 475);
    set<int> tr;
    for (int j = 0; j < 25; j++) {
      t = (t * 96 + 42) % 475;
      tr.insert(26 + t);
    }
    if (tr.find(p) != tr.end()) {
      (i - x) % 100 == 0 ? cout << (i - x) / 100
                         : cout << (i - x) / 100 + 1 << '\n';
      return 0;
    }
  }
  return 0;
}
