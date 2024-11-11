#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  vector<int> ns(n, 0);
  bool pre = 0;
  for (int i = 0; i < n; i++) {
    cin >> ns[i];
    if (ns[i] == x) pre = 1;
  }
  int c = 0;
  if (pre == 0) n++, c++, ns.push_back(x);
  sort(ns.begin(), ns.end());
  int M = INT_MAX;
  int l1 = 0, l2 = 0;
  for (int i = 0; i < n; i++) {
    if (ns[i] != x) continue;
    l1 = i;
    l2 = n - i - 1;
    if (l1 == l2) {
      M = 0;
    } else if (l1 < l2) {
      M = min(M, l2 - l1 - 1);
    } else {
      M = min(M, l1 - l2);
    }
  }
  cout << M << endl;
  return 0;
}
