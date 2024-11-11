#include <bits/stdc++.h>
using namespace std;
int n, c, nod;
set<int> gnext[1 << 20][2];
vector<int> ans;
void PANIC() {
  cout << "Impossible\n";
  exit(0);
}
void dfs(int r) {
  int onod = nod++;
  if (onod >= n) PANIC();
  if (gnext[onod][0].empty())
    ans.push_back(onod);
  else {
    if (!gnext[onod][1].empty() &&
        *gnext[onod][0].rbegin() >= *gnext[onod][1].begin())
      PANIC();
    if (*gnext[onod][0].begin() < nod) PANIC();
    dfs(*gnext[onod][0].rbegin());
    ans.push_back(onod);
  }
  if (!gnext[onod][1].empty()) {
    if (*gnext[onod][1].begin() < nod) PANIC();
    dfs(max(r, *gnext[onod][1].rbegin()));
  } else if (nod <= r)
    dfs(r);
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> c;
  for (int i = 0; i < c; i++) {
    string str;
    int a, b;
    cin >> a >> b >> str;
    a--, b--;
    if (a >= b) PANIC();
    if (str[0] == 'L')
      gnext[a][0].insert(b);
    else
      gnext[a][1].insert(b);
  }
  dfs(n - 1);
  for (int i = 0; i < n; i++) cout << ans[i] + 1 << ' ';
  cout << '\n';
  return 0;
}
