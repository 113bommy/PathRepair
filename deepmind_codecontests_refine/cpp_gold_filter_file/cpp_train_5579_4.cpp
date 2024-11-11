#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int flag = 0, ans = 0;
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    set<int> check;
    flag = 1;
    for (int j = 0; j < k; j++) {
      int t;
      cin >> t;
      if (check.count(-t) == 1) {
        flag = 0;
      }
      check.insert(t);
    }
    if (flag) ans = 1;
  }
  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
