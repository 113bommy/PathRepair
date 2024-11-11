#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> V;
  int x, pr;
  for (int i = 0; i < n; i++) {
    pr = 1;
    for (int j = 0; j < n; j++) {
      cin >> x;
      if ((j > i) && ((x == 1) || (x == 3))) {
        pr = 0;
      }
    }
    if (pr == 1) {
      V.push_back(i);
    }
  }
  cout << V.size() << endl;
  if (V.size() != 0) {
    for (int i = 0; i < (int)V.size(); i++) {
      cout << V[i] + 1 << ' ';
    }
    cout << endl;
  }
  return 0;
}
