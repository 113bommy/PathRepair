#include <bits/stdc++.h>
using namespace std;
const int K = 50010;
int n, k, li, ri, lfv, lsv, rfv, rsv;
inline int question(int i) {
  fflush(stdout);
  cout << "? " << i << endl;
  cin >> i;
  return i;
}
int main() {
  cin >> n;
  if (n % 4 != 0) {
    fflush(stdout);
    cout << -1;
    return 0;
  }
  k = n / 2;
  li = 1;
  ri = k + 1;
  lfv = rsv = question(li);
  lsv = rfv = question(ri);
  if (lfv == lsv) {
    fflush(stdout);
    cout << "! " << li;
    return 0;
  }
  while (1) {
    int i = (ri + li) / 2;
    int fv = question(i);
    int sv = question(i + k);
    if (fv == sv) {
      fflush(stdout);
      cout << "! " << i;
      return 0;
    }
    if (sv > fv == lsv > lfv) {
      lsv = sv;
      lfv = fv;
      li = i;
    } else {
      rsv = sv;
      rfv = fv;
      ri = i;
    }
  }
  return 0;
}
