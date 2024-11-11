#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
vector<int> vv;
int x[105], y[105];
int main() {
  int n, m, b, g;
  cin >> n >> m >> b;
  for (int i = 0; i < b; i++) {
    int t;
    cin >> t;
    x[t] = 1;
  }
  cin >> g;
  for (int i = 0; i < g; i++) {
    int t;
    cin >> t;
    y[t] = 1;
  }
  for (int i = 0; i < 10005; i++) {
    if (x[i % n] == 1 || y[i % m] == 1) {
      x[i % n] = 1;
      y[i % m] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (x[i] == 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  for (int i = 0; i < m; i++) {
    if (y[i] == 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
