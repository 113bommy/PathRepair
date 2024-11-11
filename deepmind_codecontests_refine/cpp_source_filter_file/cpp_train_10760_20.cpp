#include <bits/stdc++.h>
using namespace std;
int n, m, a[100];
vector<int> v[100];
int main() {
  cin >> m >> n;
  int t;
  for (int i = 1; i <= n; ++i) {
    cin >> t;
    a[t] = 1;
    v[i].push_back(t);
  }
  int i = 1, j = 1;
  while (j != n + 1) {
    while (v[j].size() != m) {
      if (!a[i]) {
        v[j].push_back(i);
        a[i] = 1;
      }
      ++i;
    }
    ++j;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < v[i].size(); ++j) cout << v[i][j] << " ";
    cout << endl;
  }
}
