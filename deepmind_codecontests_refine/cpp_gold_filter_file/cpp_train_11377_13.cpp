#include <bits/stdc++.h>
using namespace std;
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  vector<int> occ(n);
  long long res = 0, acc = 0, cur = 0;
  for (int r = 0; r < n; r++) {
    if (s[r] - '0')
      cur++;
    else {
      for (int i = 0; i < cur; occ[i] = r - i, i++)
        res += acc += r - cur + i + 1 - occ[i];
      res += acc, cur = 0;
    }
  }
  for (int i = 0; i < cur; occ[i++] = n - i + 1)
    res += acc += n - cur + i + 1 - occ[i];
  cout << res << "\n";
}
