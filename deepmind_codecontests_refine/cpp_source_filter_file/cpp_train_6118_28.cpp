#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int n, m;
int x[11], y[11];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> y[i];
  }
  int result = 0;
  vector<int> items;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (x[i] == y[j]) {
        items.push_back(x[i]);
        break;
      }
    }
  }
  for (auto value : items) {
    cout << value << ' ';
  }
  cout << endl;
  return 0;
}
