#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int flag = 0;
    int n;
    int now;
    cin >> n >> now;
    int l = now, r = now;
    int past = 0;
    for (int i = 0; i < n; i++) {
      int len, lb, rb;
      cin >> len >> lb >> rb;
      l -= len - past;
      r += len - past;
      l = max(l, lb);
      r = min(r, rb);
      if (l > r) flag = 1;
      past = now;
    }
    if (flag)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
