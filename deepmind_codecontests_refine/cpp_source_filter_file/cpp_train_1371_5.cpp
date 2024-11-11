#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
int mat[1100][1000];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<ii> ans;
  ii top(0, 0);
  ii bot(n - 1, m - 1);
  for (int i = 0; i < n * m; ++i) {
    ans.push_back(top);
    if (ans.size() == n * m) break;
    top.second++;
    if (top.second == m) {
      top.second = 0;
      top.first++;
    }
    ans.push_back(bot);
    if (ans.size() == n * m) break;
    bot.second--;
    if (bot.second == 0) {
      bot.second = m - 1;
      bot.first--;
    }
  }
  for (auto i : ans) cout << i.first + 1 << " " << i.second + 1 << '\n';
  return 0;
}
