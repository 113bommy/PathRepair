#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
long long int t, n, m;
string s[3000005];
vector<long long int> vr, vc;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int i, j, k, y;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    long long int flaga = 0, tp = 1e9, dn = -1e9, lf = 1e9, rt = -1e9;
    vr.clear();
    vc.clear();
    for (i = 0; i < n; i++) {
      cin >> s[i];
      for (j = 0; j < m; j++) {
        if (s[i][j] == 'P') {
          lf = min(lf, j);
          rt = max(rt, j);
          tp = min(tp, i);
          dn = max(dn, i);
        } else
          flaga++;
      }
    }
    if (flaga == 0) {
      cout << "MORTAL\n";
      continue;
    }
    if (flaga == (m * n)) {
      cout << "0\n";
      continue;
    }
    for (i = 0; i < n; i++) {
      long long int f1 = 0;
      for (j = lf; j <= rt; j++) {
        if (s[i][j] == 'P') {
          f1 = 1;
          break;
        }
      }
      if (f1 == 0) vr.push_back(i);
    }
    for (j = 0; j < m; j++) {
      long long int f1 = 0;
      for (i = tp; i <= dn; i++) {
        if (s[i][j] == 'P') {
          f1 = 1;
          break;
        }
      }
      if (f1 == 0) vc.push_back(i);
    }
    long long int f1 = 0;
    for (i = 0; i < vr.size(); i++) {
      if (vr[i] <= tp || vr[i] >= dn) f1 = 1;
    }
    for (i = 0; i < vc.size(); i++) {
      if (vc[i] <= lf || vc[i] >= rt) f1 = 1;
    }
    if (f1) {
      cout << "1\n";
      continue;
    }
    if (vc.size() != 0 || vr.size() != 0) {
      cout << "2\n";
      continue;
    }
    if (s[tp][lf] == 'A' || s[tp][rt] == 'A' || s[dn][lf] == 'A' ||
        s[dn][rt] == 'A') {
      cout << "2\n";
      continue;
    }
    f1 = 0;
    for (i = tp + 1; i < dn; i++) {
      if (s[i][lf] == 'A' || s[i][rt] == 'A') {
        f1 = 1;
        break;
      }
    }
    for (j = lf + 1; j < rt; j++) {
      if (s[tp][j] == 'A' || s[dn][j] == 'A') {
        f1 = 1;
        break;
      }
    }
    if (f1)
      cout << "3\n";
    else
      cout << "4\n";
  }
  return 0;
}
