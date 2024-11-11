#include <bits/stdc++.h>
using namespace std;
void solution(string x) {
  int dp = 1, cp = 0;
  vector<int> ans(10);
  while (cp >= 0 and cp < x.size()) {
    bool erase = false;
    if (x[cp] >= '0' and x[cp] <= '9') {
      if (x[cp] == '0') {
        erase = 1;
      }
      ans[x[cp] - '0']++;
      x[cp]--;
    } else {
      if (x[cp] == '>')
        dp = 1;
      else
        dp = -1;
      if (cp + dp >= 0 and cp + dp < x.size() and
          (x[cp + dp] == '>' or x[cp + dp] == '<'))
        erase = 1;
    }
    if (erase) {
      x.erase(cp, 1);
      if (dp == -1) cp--;
    } else
      cp += dp;
  }
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  ;
  int n, q;
  cin >> n >> q;
  string x;
  cin >> x;
  while (q--) {
    int l, r;
    cin >> l >> r;
    solution(x.substr(l - 1, r - l + 1));
  }
  return 0;
}
