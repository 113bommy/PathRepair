#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int p, q;
  map<int, pair<int, int>> me;
  for (int i = 0; i < n; i++) {
    cin >> p >> q;
    me[i] = make_pair(p, q);
  }
  int k;
  cin >> k;
  int res;
  for (auto it : me) {
    if (k >= it.second.first && k <= it.second.second) {
      res = n - it.first;
    }
  }
  cout << res << "\n";
}
