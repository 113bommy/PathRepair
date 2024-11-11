#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e;
  vector<int> l1;
  vector<int> l2;
  vector<int> l3;
  vector<bool> l4;
  cin >> a;
  for (int i = 0; i < a + 1; i++) l4.push_back(0);
  for (int i = 0; i < a; i++) {
    cin >> b;
    l1.push_back(b);
  }
  for (int i = 0; i < a; i++) {
    cin >> b;
    l2.push_back(b);
  }
  int t = 0;
  int s = 0;
  bool k;
  for (int i = 0; i < a; i++) {
    int u = l2[i];
    if (l4[l2[i]] == 1) {
      l3.push_back(0);
      continue;
    }
    for (int ii = t; ii < a; ii++) {
      l4[l1[ii]] = 1;
      if (u == l1[ii]) {
        l3.push_back(ii - s + 1);
        t = ii + 1;
        s = ii + 1;
        break;
      }
    }
  }
  for (int i = 0; i < a; i++) cout << l3[i] << " ";
  cout << endl;
}
