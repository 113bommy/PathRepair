#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, r;
  cin >> l >> r;
  int L = l;
  int L1 = r - l + 1, k = 0;
  int L3 = l;
  int found = 0;
  while (L1) {
    L3 = l + k;
    int L2 = L3;
    vector<int> v;
    vector<int> v1;
    while (L2) {
      int b = L2 % 10;
      v.push_back(b);
      L2 = L2 / 10;
    }
    for (int i = v.size() - 1; i >= 0; i--) {
      v1.push_back(v[i]);
    }
    for (int i = 0; i < v1.size(); i++) {
      for (int j = i + 1; j < v1.size(); j++) {
        if (v1[j] == v1[i]) {
          found = 1;
          break;
        } else
          found = 0;
      }
      if (found == 1) break;
    }
    if (found == 0) {
      cout << L3;
      break;
    }
    L1--;
    k++;
  }
  if (found == 1) cout << "-1";
  return 0;
}
