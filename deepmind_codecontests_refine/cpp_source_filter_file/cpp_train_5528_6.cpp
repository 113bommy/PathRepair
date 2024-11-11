#include <bits/stdc++.h>
using namespace std;
const int lim = 2e5 + 5;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  s += s;
  int cnt = 0;
  char lseen = 'g';
  int n = s.size();
  int gcnt = 1;
  for (int i = 0; i < n; ++i) {
    if (lseen != s[i])
      ++cnt;
    else
      cnt = 1;
    lseen = s[i];
    gcnt = max(gcnt, cnt);
  }
  cout << max(n / 2, gcnt);
  return 0;
}
