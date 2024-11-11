#include <bits/stdc++.h>
using namespace std;
int a[200];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
      cin >> a[i];
    }
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      mp[x] = 1;
    }
    for (int i = 1; i < m; i++) {
      for (int j = m - i; j <= m; j++) {
        if (j + 1 <= m && a[j] > a[j + 1]) {
          if (mp[j]) {
            swap(a[j], a[j + 1]);
          }
        }
      }
    }
    int flag = 1;
    for (int i = 1; i < m; i++) {
      if (a[i] > a[i + 1]) {
        flag = 0;
      }
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
