#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  string fuhao;
  char ch;
  int lef = -1000000000, rig = 1000000000, x;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    cin >> fuhao >> x >> ch;
    if (fuhao == ">") {
      if (ch == 'Y') {
        if (lef < x + 1) lef = x + 1;
      } else {
        if (rig > x) rig = x;
      }
    } else if (fuhao == ">=") {
      if (ch == 'Y') {
        if (lef < x) lef = x;
      } else {
        if (rig > x - 1) rig = x - 1;
      }
    } else if (fuhao == "<") {
      if (ch == 'Y') {
        if (rig > x - 1) rig = x - 1;
      } else {
        if (lef < x) lef = x;
      }
    } else if (fuhao == "<=") {
      if (ch == 'Y') {
        if (rig > x) rig = x;
      } else {
        if (lef < x + 1) lef = x + 1;
      }
    }
  }
  if (lef > rig)
    cout << "Impossible" << endl;
  else
    cout << lef << endl;
  return 0;
}
