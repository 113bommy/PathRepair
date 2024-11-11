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
    flag = 0;
    for (int i = 0; i < k; i++) {
      int t;
      cin >> t;
      if (check.count(-t)) {
        flag = 1;
      }
      check.insert(t);
    }
    if (!flag) ans = 1;
  }
  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
