#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  vector<int> x_0;
  vector<int> y_w;
  vector<int> x_h;
  vector<int> y_0;
  long long a, b, c, d;
  int u;
  int k, w, h;
  while (t--) {
    cin >> w >> h;
    cin >> k;
    while (k--) {
      cin >> u;
      x_0.push_back(u);
    }
    a = x_0[x_0.size() - 1] - x_0[0];
    cin >> k;
    while (k--) {
      cin >> u;
      x_h.push_back(u);
    }
    c = x_h[x_h.size() - 1] - x_h[0];
    cin >> k;
    while (k--) {
      cin >> u;
      y_0.push_back(u);
    }
    d = y_0[y_0.size() - 1] - y_0[0];
    cin >> k;
    while (k--) {
      cin >> u;
      y_w.push_back(u);
    }
    b = y_w[y_w.size() - 1] - y_w[0];
    a = (a > c) ? a : c;
    a = a * h;
    b = (b > d) ? b : d;
    b = b * w;
    a = (a > b) ? a : b;
    cout << a << "\n";
    x_0.clear();
    y_0.clear();
    x_h.clear();
    y_w.clear();
  }
  return 0;
}
