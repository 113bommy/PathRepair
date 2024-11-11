#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  set<pair<int, int>> a, b;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.insert({x, i + 1});
  }
  for (int i = 0; i < 2 * n; i++) {
    char c;
    cin >> c;
    if (c == '0') {
      auto it = *a.begin();
      cout << it.second << " ";
      a.erase(it);
      b.insert(it);
    } else {
      auto it = *b.begin();
      b.erase(it);
      cout << it.second << " ";
    }
  }
}
