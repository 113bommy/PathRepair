#include <bits/stdc++.h>
using namespace std;
vector<string> ans[(int)5e5] = {};
string arr[(int)5e5] = {};
int cnt[(int)5e5] = {};
int prv = -1, nxt = -1, j = 0, ind = 0, mx = 0;
string s, lol;
void dfs(int dep) {
  if (ind >= j) return;
  int cp = ind;
  for (int i = 0; i < cnt[cp]; i++) {
    ind++;
    dfs(dep + 1);
  }
  ans[dep].push_back(arr[cp]);
  mx = max(mx, dep);
}
int main() {
  cin >> s;
  while (1) {
    prv = nxt;
    nxt = s.find(',', nxt + 1);
    if (nxt == string::npos) break;
    if (j % 2 == 0)
      arr[j / 2] = s.substr(prv + 1, nxt - prv - 1);
    else {
      lol = s.substr(prv + 1, nxt - prv - 1);
      for (int i = 0; i < lol.size(); i++)
        cnt[(j - 1) / 2] += (lol[i] - '0') * round(pow(10, lol.size() - i - 1));
    }
    j++;
  }
  cnt[(j - 1) / 2] = 0;
  j = (j + 1) / 2;
  while (ind < j) dfs(0), ind++;
  cout << mx + 1 << "\n";
  for (int i = 0; !ans[i].empty(); i++) {
    for (int k = 0; k < ans[i].size(); k++) cout << ans[i][k] << ' ';
    cout << "\n";
  }
  return 0;
}
