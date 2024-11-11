#include <bits/stdc++.h>
using namespace std;
int main() {
  int queries;
  cin >> queries;
  for (int q = 0; q < queries; q++) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& x : p) cin >> x;
    if (n < 3) {
      cout << "YES" << endl;
      continue;
    }
    bool cw = true;
    bool ccw = true;
    for (int i = 0; i < p.size(); i++) {
      int curr = p[i];
      int next = (i < p.size() - 1 ? p[i + 1] : p[0]);
      if (curr + 1 != next && next != 1) {
        cw = false;
        break;
      }
    }
    for (int i = 0; i < p.size(); i++) {
      int curr = p[i];
      int next = (i < p.size() - 1 ? p[i + 1] : p[0]);
      if (curr - 1 != next && next != n) {
        ccw = false;
        break;
      }
    }
    cout << (cw || ccw ? "YES" : "NO") << endl;
  }
  return EXIT_SUCCESS;
}
