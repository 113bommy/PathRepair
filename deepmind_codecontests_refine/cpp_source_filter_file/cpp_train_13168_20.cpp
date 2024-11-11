#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
map<int, int> b, s;
int n, t, t_1;
char c;
int main(void) {
  scanf("%d%d", &n, &t);
  for (int x, y, i = 1; i <= n; ++i) {
    cin >> c;
    scanf("%d%d", &x, &y);
    if (c == 'B')
      b[x] = b[x] + y;
    else
      s[x] = s[x] + y;
  }
  vector<pair<int, int>> ans, ans_1;
  t_1 = t;
  for (auto it = s.rbegin(); it != s.rend() && t; ++it) {
    ans.push_back({it->first, it->second});
    t = t - 1;
  }
  for (auto it = b.rbegin(); it != b.rend() && t_1; ++it) {
    ans_1.push_back({it->first, it->second});
    t_1 = t_1 - 1;
  }
  sort(ans.rbegin(), ans.rend());
  sort(ans_1.rbegin(), ans_1.rend());
  for (int i = 0; i < ans.size(); ++i) {
    printf("S %d %d\n", ans[i].first, ans[i].second);
  }
  for (int i = 0; i < ans_1.size(); ++i) {
    printf("B %d %d\n", ans_1[i].first, ans_1[i].second);
  }
}
