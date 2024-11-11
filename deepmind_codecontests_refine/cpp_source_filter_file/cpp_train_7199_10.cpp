#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, a[200020], b[200020], last = -1, nex = -1;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    if (b[i] != 0) last = max(last, i - b[i] + 1);
    if (nex == -1 && b[i] == 1)
      nex = 2;
    else if (nex == b[i])
      nex++;
    else
      nex = -1;
  }
  if (nex == -1)
    cout << last + 1 + n << endl;
  else {
    if (nex == n + 1) {
      cout << 0 << endl;
      return 0;
    }
    bool hv[200020] = {};
    for (int i = 0; i < n; i++) {
      hv[a[i]] = true;
    }
    for (int i = 0; i < n; i++) {
      if (hv[nex]) {
        nex++;
        hv[nex] = false;
        hv[b[i]] = true;
        if (nex == n + 1) {
          cout << i + 1 << endl;
          return 0;
        }
      } else {
        cout << last + 1 + n << endl;
        return 0;
      }
    }
  }
}
