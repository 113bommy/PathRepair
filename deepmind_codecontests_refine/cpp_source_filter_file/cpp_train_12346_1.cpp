#include <bits/stdc++.h>
using namespace std;
long double esp = 1e-11;
const long double PI = acos((long double)-1);
const long long int INF = 0x3f3f3f3fll;
const int MOD = 1000000007ll;
const int maxn = 200010;
vector<pair<int, int> > q[2];
priority_queue<pair<pair<int, int>, int> > p;
int main() {
  int n, c, d;
  scanf("%d%d%d", &n, &c, &d);
  for (int x = 1; x <= n; x++) {
    int a, b;
    char s[5];
    scanf("%d%d%s", &a, &b, s);
    if (s[0] == 'C')
      q[0].push_back(make_pair(b, a));
    else
      q[1].push_back(make_pair(b, a));
  }
  int ans = 0;
  sort((q[0]).begin(), (q[0]).end());
  sort((q[1]).begin(), (q[1]).end());
  int len1 = q[0].size(), len2 = q[1].size();
  if (len1 > 1) {
    while (!p.empty()) p.pop();
    for (int x = 0; x < len1; x++)
      p.push(make_pair(make_pair(q[0][x].second, q[0][x].first), x));
    for (int x = 0; x < len1; x++) {
      while (!p.empty() && q[0][x].first + p.top().first.second > c) p.pop();
      if (!p.empty()) {
        if (x != p.top().second)
          ans = max(ans, q[0][x].second + p.top().first.first);
        else {
          pair<pair<int, int>, int> tem = p.top();
          p.pop();
          while (!p.empty() && q[0][x].first + p.top().first.second > c)
            p.pop();
          if (!p.empty()) ans = max(ans, q[0][x].second + p.top().first.first);
          p.push(tem);
        }
      }
    }
  }
  if (len2 > 1) {
    while (!p.empty()) p.pop();
    for (int x = 0; x < len2; x++)
      p.push(make_pair(make_pair(q[1][x].second, q[1][x].first), x));
    for (int x = 0; x < len2; x++) {
      while (!p.empty() && q[1][x].first + p.top().first.second > d) p.pop();
      if (!p.empty()) {
        if (x != p.top().second)
          ans = max(ans, q[1][x].second + p.top().first.first);
        else {
          pair<pair<int, int>, int> tem = p.top();
          p.pop();
          while (!p.empty() && q[1][x].first + p.top().first.second > d)
            p.pop();
          if (!p.empty()) ans = max(ans, q[1][x].second + p.top().first.first);
          p.push(tem);
        }
      }
    }
  }
  int ma1 = -1, ma2 = -1;
  for (int x = 0; x < len1; x++)
    if (q[0][x].first <= c) ma1 = max(ma1, q[0][x].second);
  for (int x = 0; x < len2; x++)
    if (q[1][x].first <= c) ma2 = max(ma2, q[1][x].second);
  if (ma1 != -1 && ma2 != -1) ans = max(ans, ma1 + ma2);
  printf("%d\n", ans);
  return 0;
}
