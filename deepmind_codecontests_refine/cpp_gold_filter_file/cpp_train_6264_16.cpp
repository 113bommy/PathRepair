#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    int a[n], d, c = 0;
    set<int> second;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      d = a[i];
      second.insert(d);
    }
    int flag = 0;
    if (second.size() < n) {
      cout << "NO" << endl;
    } else {
      for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1] && c == 1) {
          c = -1;
        }
        if (a[i] < a[i - 1] && c == 0) {
          c = 1;
        }
      }
      if (c < 0) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
  return 0;
}
