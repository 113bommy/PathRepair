#include <bits/stdc++.h>
using namespace std;
const int xy[4][2] = {{0, 0}, {-1, 0}, {0, -1}, {-1, -1}};
pair<int, int> a[4], goal[4];
int ans;
vector<pair<int, int> > bot;
void fix(int d) {
  bot.clear();
  for (int i = 0; i < 4; i++)
    for (int sig = -1; sig <= 1; sig++)
      for (int j = 0; j < 4; j++)
        for (int ss = -1; ss <= 1; ss++)
          bot.push_back(
              pair<int, int>(a[i].first + sig * d, a[j].second + sig * d));
  int p[4] = {0, 1, 2, 3};
  do {
    pair<int, int> b[4];
    for (int i = 0; i < 4; i++) {
      b[i] = a[p[i]];
      b[i].first += xy[i][0] * d, b[i].second += xy[i][1] * d;
    }
    auto trans = [](vector<pair<int, int> > &bot, pair<int, int> *b, bool ty) {
      if (b[1].first == b[0].first && b[2].first == b[1].first &&
          b[3].first == b[2].first) {
        vector<int> y = {b[0].second, b[1].second, b[2].second, b[3].second};
        sort(y.begin(), y.end());
        bot.push_back(pair<int, int>(b[0].first, (y[0] + y[3]) / 2));
        if (ty) swap(bot[bot.size() - 1].first, bot[bot.size() - 1].second);
      }
    };
    trans(bot, b, 0);
    for (int i = 0; i < 4; i++) swap(b[i].first, b[i].second);
    trans(bot, b, 1);
  } while (next_permutation(p, p + 4));
  sort(bot.begin(), bot.end());
  bot.resize(unique(bot.begin(), bot.end()) - bot.begin());
  for (auto p1 : bot) {
    do {
      bool legal = 1;
      int dis[4];
      for (int i = 0; i < 4; i++) {
        pair<int, int> co = a[p[i]], go = p1;
        go.first -= xy[i][0] * d, go.second -= xy[i][1] * d;
        if (co.first == go.first)
          dis[i] = abs(go.second - co.second);
        else if (co.second == go.second)
          dis[i] = abs(go.first - co.first);
        else
          legal = 0;
      }
      if (legal) {
        int v = max({dis[0], dis[1], dis[2], dis[3]});
        if (v < ans) {
          ans = v;
          for (int i = 0; i < 4; i++) {
            int pos;
            for (pos = 0; pos < 4; pos++)
              if (p[pos] == i) break;
            goal[i] = p1;
            goal[i].first -= xy[pos][0] * d, goal[i].second -= xy[pos][1] * d;
          }
        }
      }
    } while (next_permutation(p, p + 4));
  }
}
void work() {
  for (int i = 0; i < 4; i++) cin >> a[i].first >> a[i].second;
  ans = (1 << 30);
  for (int i = 0; i < 4; i++)
    for (int j = i + 1; j < 4; j++) {
      fix(abs(a[i].first - a[j].first));
      fix(abs(a[i].second - a[j].second));
    }
  if (ans == (1 << 30)) {
    cout << -1 << endl;
    return;
  }
  cout << ans << endl;
  for (int i = 0; i < 4; i++)
    cout << goal[i].first << " " << goal[i].second << endl;
}
int main() {
  int t;
  cin >> t;
  for (; t; t--) work();
  return 0;
}
