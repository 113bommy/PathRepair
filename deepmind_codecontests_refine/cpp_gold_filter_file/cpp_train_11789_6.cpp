#include <bits/stdc++.h>
using namespace std;
int main() {
std:
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, last = -1;
    cin >> n;
    bool g[100005];
    for (int i = 1; i <= n; i++) {
      g[i] = false;
    }
    for (int i = 0; i < n; i++) {
      int m;
      cin >> m;
      bool flag = false;
      for (int j = 0; j < m; j++) {
        int l;
        cin >> l;
        if (!flag && g[l] == false) {
          g[l] = true;
          flag = true;
        }
      }
      if (!flag) {
        last = i;
      }
    }
    if (last == -1) {
      cout << "OPTIMAL\n";
    } else {
      for (int i = 1; i <= n; i++) {
        if (g[i] == false) {
          cout << "IMPROVE\n" << last + 1 << " " << i << endl;
          break;
        }
      }
    }
  }
  return 0;
}
