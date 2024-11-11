#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int lig_kni[n + 1], ned_col[m + 1], rs = 2e6, done = 0, need = 0;
  for (int i = 1; i < n + 1; ++i) cin >> lig_kni[i];
  for (int i = 1; i < m + 1; ++i)
    cin >> ned_col[i], need += ned_col[i], done += ned_col[i] == 0;
  int i = 1, j = 1;
  while (i < n + 1 && j < n + 1) {
    while (i < n + 1 && done != m) {
      ned_col[lig_kni[i]]--;
      if (ned_col[lig_kni[i]] == 0) done++;
      i++;
    }
    while (j < n + 1 && ned_col[lig_kni[j]] < 0 && done == m) {
      ned_col[lig_kni[j]]++;
      j++;
    }
    if (done == m) rs = min(rs, i - j);
    ned_col[lig_kni[j]]++;
    done--;
    j++;
  }
  if (rs != 2e6)
    cout << rs - need;
  else
    cout << -1;
  return 0;
}
