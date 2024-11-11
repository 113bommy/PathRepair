#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, c[100], x, y, all = 0;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> c[i];
    all += c[i];
  }
  cin >> x >> y;
  int nfrat = 0;
  int in = -1;
  while (nfrat < x) {
    nfrat += c[++in];
  }
  int tmp = in;
  if (nfrat > y) {
    cout << 0 << endl;
    return 0;
  } else if (all - nfrat >= x && all - nfrat <= y) {
    cout << in + 2 << endl;
    return 0;
  } else {
    while (nfrat + c[in + 1] <= y) {
      nfrat += c[++in];
      if (nfrat >= x && nfrat <= y && all - nfrat >= x && all - nfrat <= y) {
        cout << in + 2 << endl;
        return 0;
      }
    }
    if (in == tmp) {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  cin >> x;
  return 0;
}
