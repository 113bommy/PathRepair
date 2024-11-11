#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000000000;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int kol_vo, m;
  cin >> kol_vo >> m;
  vector<int> v(kol_vo + 2);
  for (int c = 1; c <= kol_vo; c++) cin >> v[c];
  v[kol_vo + 1] = m;
  int gor = 0, negor = 0;
  for (int c = 0; c <= kol_vo; c++) {
    if (c % 2 == 0)
      gor += (v[c + 1] - v[c]);
    else
      negor += (v[c + 1] - v[c]);
  }
  int mmax = gor;
  int alrgor = 0;
  for (int c = 0; c <= kol_vo + 1; c++) {
    mmax = max(mmax, alrgor + negor - 1);
    if (c % 2 == 1)
      alrgor += (v[c] - v[c - 1]);
    else {
      if (c) negor -= (v[c] - v[c - 1]);
    }
  }
  cout << mmax;
  return 0;
}
