#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string p = "BRG", s, t = "";
  int n;
  cin >> n >> s;
  vector<string> vec;
  for (int i = 0; i < n; i++) {
    if (i % 3 == 0 && i != 0) {
      vec.push_back(t);
      t = "";
    }
    t += s[i];
  }
  if (t.size() != 0) vec.push_back(t);
  int ans = 1e9;
  string r = "";
  do {
    int cnt = 0;
    for (int i = 0; i < (int)vec.size(); i++) {
      if (vec[i].size() == 3) {
        cnt += (vec[i][0] != p[0]);
        cnt += (vec[i][1] != p[1]);
        cnt += (vec[i][2] != p[2]);
      } else if (vec[i].size() == 2) {
        cnt += (vec[i][0] != p[0]);
        cnt += (vec[i][1] != p[1]);
      } else if (vec[i].size() == 1) {
        cnt += (vec[i][0] != p[0]);
      }
    }
    if (cnt < ans) {
      r = p;
    }
    ans = min(ans, cnt);
  } while (next_permutation(p.begin(), p.end()));
  cout << ans << '\n';
  for (int i = 0; i < (int)vec.size(); i++) {
    if (vec[i].size() == 3) {
      cout << r;
    } else if (vec[i].size() == 2) {
      cout << r[0] << r[1];
    } else if (vec[i].size() == 1) {
      cout << r[0];
    }
  }
  cout << '\n';
  return 0;
}
