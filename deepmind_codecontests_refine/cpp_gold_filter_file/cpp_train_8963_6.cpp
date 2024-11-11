#include <bits/stdc++.h>
using namespace std;
long long int ans;
int arr[300009];
void solve() {
  map<int, pair<char, int>> hshmp;
  bool ok = false;
  int n, m, k;
  cin >> n;
  int shiftl = 0;
  int shiftr = 0;
  for (int i = 0; i < n; ++i) {
    char ch;
    cin >> ch;
    cin >> k;
    if (ch == 'L') {
      shiftl++;
      hshmp[k] = make_pair('L', shiftl);
    } else if (ch == 'R') {
      shiftr++;
      hshmp[k] = make_pair('R', shiftr);
    } else {
      auto v = hshmp[k];
      int occ = v.second;
      if (v.first == 'R')
        ans = min(shiftr - occ, shiftl + occ - 1);
      else
        ans = min(shiftr + occ - 1, shiftl - occ);
      cout << ans << '\n';
    }
  }
  ans = 0;
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
