#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int h;
  cin >> h;
  int old, nw[h + 1];
  bool f = true;
  for (int i = 0; i <= h; i++) {
    cin >> nw[i];
    if (i == 0) continue;
    if (nw[i] > 1 && nw[i - 1] > 1) f = false;
  }
  if (f)
    cout << "perfect" << endl;
  else {
    cout << "ambiguous" << endl;
    int past = 1;
    for (int i = 0; i <= h; i++) {
      if (i == 0)
        cout << 0 << " ";
      else {
        for (int j = 1; j <= nw[i]; j++) cout << past << " ";
        past += nw[i];
      }
    }
    cout << endl;
    past = 1;
    for (int i = 0; i <= h; i++) {
      if (i == 0)
        cout << 0 << " ";
      else {
        cout << past - nw[i - 1] + 1 << " ";
        for (int j = 2; j <= nw[i]; j++) cout << past << " ";
        past += nw[i];
      }
    }
  }
  return 0;
}
