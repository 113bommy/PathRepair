#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long i, j, k, l, m, n, s, f;
  cin >> n >> m >> s >> f;
  long long curr = s, dest = f;
  vector<vector<long long> > req;
  for (i = 0; i < m; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    req.push_back({a, b, c});
  }
  long long i1 = 0;
  string ans;
  for (i = 1; i <= 3e5 && curr != dest; i++) {
    long long lft = 0, rt = 0;
    if (i1 < (long long)req.size() && req[i1][0] == i) {
      lft = req[i1][1], rt = req[i1][2];
      i1++;
    }
    if (curr > rt || curr < lft) {
      if (curr < dest) {
        if (curr + 1 > rt || curr + 1 < lft)
          ans.push_back('R'), curr++;
        else
          ans.push_back('X');
      }
      if (curr > dest) {
        if (curr - 1 > rt || curr - 1 < lft)
          ans.push_back('L'), curr--;
        else
          ans.push_back('X');
      }
    } else
      ans.push_back('X');
  }
  cout << ans << "\n";
  return 0;
}
