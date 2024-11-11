#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  set<pair<int, int> > s;
  int n;
  cin >> n;
  vector<int> x, y;
  for (int i = 1; i <= n; ++i) {
    int a, b;
    cin >> a >> b;
    x.push_back(a);
    y.push_back(b);
    s.insert(make_pair(a, b));
  }
  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if ((x[i] + x[j]) % 2 == 0 && (y[i] + y[j]) % 2 == 0) {
        int m = (x[i] + x[j]) / 2;
        int n = (y[i] + y[j]) / 2;
        if (s.find(make_pair(m, n)) != s.end()) {
          ++count;
        }
      }
    }
  }
  cout << count << "\n";
}
