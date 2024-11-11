#include <bits/stdc++.h>
using namespace std;
using lli = unsigned long long int;
int main() {
  int t;
  cin >> t;
  long long int nn, mm;
  while (t--) {
    cin >> nn >> mm;
    lli n = nn, m = mm;
    vector<int> a(m);
    map<lli, lli> ma;
    for (lli i = 0; i < (m); i++) {
      cin >> a[i];
      ma[a[i]]++;
    }
    int cost = 0;
    for (lli i = 0; i < (65); i++) {
      if ((n >> i) & 1) {
        lli y = lli(1) << i;
        if (ma[y] > 0) {
          ma[y]--;
          ma[y << 1] += ma[y] / 2;
        } else {
          for (int j = i + 1; j < 65; j++) {
            if (ma[lli(1) << j] > 0) {
              for (int l = j; l > i; l--) {
                ma[lli(1) << l]--;
                ma[lli(1) << (l - 1)] += 2;
                cost += 1;
              }
              break;
            }
          }
          if (ma[y] == 0) {
            cout << -1 << endl;
            goto top;
          }
        }
      } else if (i != 64) {
        ma[lli(1) << (i + 1)] += ma[lli(1) << i] / 2;
      }
    }
    cout << cost << endl;
  top:
    continue;
  }
}
