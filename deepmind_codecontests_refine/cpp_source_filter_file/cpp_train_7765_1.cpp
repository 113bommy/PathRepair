#include <bits/stdc++.h>
using namespace std;
int n, x, l, r, m;
int main() {
  cin >> n;
  int endtime = 0;
  while (n--) {
    cin >> x;
    endtime += x;
  }
  cin >> m;
  while (m--) {
    cin >> l >> r;
    if (endtime <= l) {
      cout << l << endl;
      return 0;
    } else if (endtime > l) {
      continue;
    } else {
      cout << endtime << endl;
      return 0;
    }
  }
  cout << "-1" << endl;
  return 0;
}
