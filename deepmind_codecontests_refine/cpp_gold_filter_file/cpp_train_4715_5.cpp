#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int t, n, len[2][1010];
bitset<2000010> dp[510];
vector<int> u, d, l, r;
vector<pair<int, int> > ans1, ans2, ans3;
pair<vector<int>, vector<int> > check(int w) {
  for (int i = 0; i < n + 5; i++) dp[i].reset();
  dp[0][1000005] = 1;
  for (int i = 0; i < n; i++) {
    dp[i + 1] |= (dp[i] >> len[w][i]);
    dp[i + 1] |= (dp[i] << len[w][i]);
  }
  if (dp[n][1000005] == 0) return {{-1}, {-1}};
  int cur = 1000005, ii = n;
  pair<vector<int>, vector<int> > ret;
  ret.first.clear();
  ret.second.clear();
  while (ii > 0) {
    if (dp[ii - 1][cur - len[w][ii - 1]] == 1)
      ret.first.push_back(len[w][ii - 1]), cur -= len[w][ii - 1];
    else
      ret.second.push_back(len[w][ii - 1]), cur += len[w][ii - 1];
    --ii;
  }
  return ret;
}
int main() {
  cin >> t;
  for (int tn = 0; tn < t; tn++) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &len[1][i]);
    int tmp;
    scanf("%d", &tmp);
    for (int i = 0; i < tmp; i++) scanf("%d", &len[0][i]);
    if (n != tmp) {
      puts("No");
      continue;
    }
    pair<vector<int>, vector<int> > sv = check(0);
    if (sv.first.size() > sv.second.size()) swap(sv.first, sv.second);
    d = sv.first;
    u = sv.second;
    sv = check(1);
    if (sv.first.size() > sv.second.size()) swap(sv.first, sv.second);
    r = sv.first;
    l = sv.second;
    if (d[0] == -1 || u[0] == -1 || r[0] == -1 || l[0] == -1) {
      puts("No");
      continue;
    }
    ans1.clear();
    ans2.clear();
    ans3.clear();
    sort(r.begin(), r.end());
    reverse(r.begin(), r.end());
    sort(u.begin(), u.begin() + (int)r.size());
    int x = 0, y = 0;
    ans1.push_back(make_pair(x, y));
    for (int i = 0; i < r.size(); i++) {
      x += r[i];
      ans1.push_back(make_pair(x, y));
      y += u[i];
      ans1.push_back(make_pair(x, y));
    }
    sort(d.begin(), d.end());
    reverse(d.begin(), d.end());
    sort(l.begin(), l.begin() + (int)d.size());
    x = 0;
    y = 0;
    ans2.push_back(make_pair(x, y));
    for (int i = 0; i < d.size(); i++) {
      y += d[i];
      ans2.push_back(make_pair(x, y));
      x += l[i];
      ans2.push_back(make_pair(x, y));
    }
    puts("YES");
    for (int i = 0; i < ans1.size(); i++)
      printf("%d %d\n", ans1[i].first, ans1[i].second);
    if (ans1.back() == ans2.back()) {
      for (int i = ans2.size() - 2; i > 0; --i)
        printf("%d %d\n", ans2[i].first, ans2[i].second);
      continue;
    }
    ans3.push_back(ans1.back());
    x = ans1.back().first;
    y = ans1.back().second;
    for (int i = 0; i < u.size() - r.size(); i++) {
      x -= l[i + d.size()];
      ans3.push_back(make_pair(x, y));
      y += u[i + r.size()];
      ans3.push_back(make_pair(x, y));
    }
    for (int i = 1; i <= ans3.size() - 1; i++)
      printf("%d %d\n", ans3[i].first, ans3[i].second);
    for (int i = ans2.size() - 2; i > 0; --i)
      printf("%d %d\n", ans2[i].first, ans2[i].second);
  }
  return 0;
}
