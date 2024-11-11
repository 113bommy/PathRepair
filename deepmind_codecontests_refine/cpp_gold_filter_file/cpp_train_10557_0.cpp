#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (k == 0) {
    for (int i = 1; i <= 2 * n; i++) cout << i << " ";
    cout << endl;
    return 0;
  } else {
    vector<int> v;
    v.push_back(1);
    v.push_back(1 + k);
    if (k == 1) {
      v.push_back(3 + k);
      v.push_back(3);
    } else {
      v.push_back(2 + k);
      v.push_back(2);
    }
    set<int> s(v.begin(), v.end());
    for (int i = 1; i <= 2 * n; i++) {
      if (s.count(i)) continue;
      v.push_back(i);
    }
    for (int i : v) cout << i << " ";
    cout << endl;
  }
}
