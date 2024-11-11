#include <bits/stdc++.h>
using namespace std;
int main() {
  int Q;
  cin >> Q;
  while (Q--) {
    int n;
    cin >> n;
    vector<vector<int>> d(2, vector<int>());
    for (int i = 0; i < n; ++i) {
      int t;
      cin >> t;
      d[t & 1].push_back(t);
    }
    if (d[0].empty() && d[1].size() < 2) {
      cout << "-1\n";
    } else if (!d[0].empty()) {
      cout << "1\n" << d[0][0] << endl;
    } else {
      cout << "2\n" << d[1][0] << " " << d[1][1] << endl;
    }
  }
}
