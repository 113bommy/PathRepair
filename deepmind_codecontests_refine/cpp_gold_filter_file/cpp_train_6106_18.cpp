#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using cd = complex<double>;
int main() {
  int n;
  cin >> n;
  int ar[n];
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  string st;
  cin >> st;
  int li = -(ll)(1e9), la = (ll)(1e9), ri = -(ll)(1e9), ra = (ll)(1e9), cc = 4;
  for (int i = 4; i < st.size(); i++) {
    if (st[i] == st[i - 1]) {
      cc++;
    } else {
      cc = 0;
    }
    if (st[i] == '1' && st[i - 1] == '0') {
      for (int j = 0; j <= 4; j++) {
        li = max(ar[i - j] + 1, li);
      }
    } else if (st[i] == '0' && st[i - 1] == '1') {
      for (int j = 0; j <= 4; j++) {
        ra = min(ar[i - j] - 1, ra);
      }
    } else if (st[i] == '0' && cc > 4) {
      int ma = ar[i - 1];
      for (int j = 0; j <= 4; j++) {
        ma = max(ar[i - j], ma);
      }
      la = min(ma, la);
    } else if (st[i] == '1' && cc > 4) {
      int mi = ar[i - 1];
      for (int j = 0; j <= 4; j++) {
        mi = min(ar[i - j], mi);
      }
      ri = max(mi, ri);
    }
  }
  cout << li << " " << ra << "\n";
}
