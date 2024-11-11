#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
int main() {
  ios_base::sync_with_stdio(false);
  int t, n, x, ae, ao, be, bo;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    ae = 0;
    ao = 0;
    for (int j = 0; j < n; j++) {
      cin >> x;
      if (x % 2 == 0)
        ae++;
      else
        ao++;
    }
    cin >> n;
    be = 0;
    bo = 0;
    for (int j = 0; j < n; j++) {
      cin >> x;
      if (x % 2 == 0)
        be++;
      else
        bo++;
    }
    cout << ae * be + ao * bo << endl;
  }
  return 0;
}
