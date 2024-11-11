#include <bits/stdc++.h>
using namespace std;
vector<int> a, b;
int main() {
  int n, l, r;
  int t;
  cin >> n >> l >> r;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    a.push_back(t);
  }
  for (int i = 0; i < n; ++i) {
    cin >> t;
    b.push_back(t);
  }
  int det = 1;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i] && (i < l - 1 || i > r)) {
      cout << "LIE" << endl;
      det = 0;
      break;
    }
  }
  if (det) {
    cout << "TRUTH" << endl;
  }
  return 0;
}
