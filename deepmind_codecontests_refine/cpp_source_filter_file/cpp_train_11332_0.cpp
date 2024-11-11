#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  for (auto& e : a) cin >> e;
  for (auto& e : b) cin >> e;
  for (int i = 0; i < n - m; i++) {
    for (int j = 0; j < n - m; j++) {
      bool isInclude = true;
      for (int k = 0; k < m; k++) {
        if (a.at(i + k).substr(j, m) != b.at(k)) isInclude = false;
      }
      if (isInclude) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
