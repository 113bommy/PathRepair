#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int ts = 0; ts < T; ts++) {
    int n;
    vector<int> a, b;
    cin >> n;
    int fn = -20;
    int fp = -20;
    for (int i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      if (fn == -20 && tmp == -1) {
        fn = i;
      }
      if (fp == -20 && tmp == 1) {
        fp = i;
      }
      a.push_back(tmp);
    }
    bool possible = true;
    for (int i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      b.push_back(tmp);
    }
    for (int i = 0; i < n; i++) {
      int diff = b[i] - a[i];
      if ((diff != 0) && i == 0) {
        possible = false;
        break;
      }
      if ((diff > 0) && ((fp > i - 1) || fp == -20)) {
        possible = false;
        break;
      }
      if ((diff < 0) && ((fn > i - 1) || fn == -20)) {
        possible = false;
        break;
      }
    }
    cout << (possible ? "YES" : "NO") << endl;
  }
  return 0;
}
