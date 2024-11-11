#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> child(n);
  vector<int> s(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    child.at(a - 1).push_back(b - 1);
  }
  for (int i = 0; i < q; i++) {
    int p, x;
    cin >> p >> x;
    s.at(p - 1) += x;
  }
  for (int i = 0; i < n; i++) {
    for (auto t : child.at(i)) {
      s.at(t) += s.at(i);
    }
  }
  for (int i = 0; i < n - 1; i++) {
    cout << s.at(i) << " ";
  }
  cout << s.at(n - 1) << endl;
}
