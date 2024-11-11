#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
int dx[] = {1, -1, 1, -1, 2, -2, 2, -2};
int dy[] = {2, 2, -2, -2, 1, 1, -1, -1};
const int N = 1024;
int W[N][N], B[N][N];
void solve() {
  int n, m;
  cin >> n >> m;
  pi w, b;
  cin >> w.first >> w.second >> b.first >> b.second;
  memset(W, 0x3f, sizeof W);
  memset(B, 0x3f, sizeof B);
  auto build = [&](pi s, int d[N][N]) {
    queue<pi> q;
    q.push(s);
    d[s.first][s.second] = 0;
    while (!q.empty()) {
      int first, second;
      tie(first, second) = q.front();
      q.pop();
      for (int _ = 0; _ < 8; _++) {
        int i = first + dx[_];
        int j = second + dy[_];
        if (1 <= i && i <= n && 1 <= j && j <= m) {
          if (d[i][j] > d[first][second] + 1) {
            d[i][j] = d[first][second] + 1;
            q.emplace(i, j);
          }
        }
      }
    }
  };
  build({n / 2, m / 2}, W);
  build({n / 2 + 1, m / 2}, B);
  int tw = W[w.first][w.second];
  int tb = B[b.first][b.second];
  auto ck = [&](pi u, pi v) {
    int first = abs(u.first - v.first);
    int second = abs(u.second - v.second);
    return first + second == 3 && (first == 1 || first == 2);
  };
  pi my, enemy;
  auto go = [&](pi u) {
    my = u;
    cout << my.first << ' ' << my.second << endl;
    if (my == enemy) exit(0);
    cin >> enemy.first >> enemy.second;
  };
  auto goforit = [&](int d[N][N]) {
    while (true) {
      int first, second;
      tie(first, second) = my;
      if (d[first][second] == 0) break;
      if (ck(my, enemy)) go(enemy);
      for (int _ = 0; _ < 8; _++) {
        int i = first + dx[_];
        int j = second + dy[_];
        if (1 <= i && i <= n && 1 <= j && j <= m) {
          if (d[i][j] == d[first][second] - 1) {
            pi p{i, j};
            if (!ck(p, enemy)) {
              go(p);
              break;
            }
          }
        }
      }
    }
  };
  if (tw - tb >= 3 || tw - tb == 1) {
    int t = B[w.first][w.second];
    if ((tw - tb) % 2 == 1 || tb < t - 1) {
      cout << "BLACK" << endl;
      cin >> w.first >> w.second;
      my = b;
      enemy = w;
      goforit(B);
    } else {
      cout << "WHITE" << endl;
      my = w;
      enemy = b;
      goforit(B);
      goforit(W);
    }
  } else if (tb - tw >= 2 || tb == tw) {
    int t = W[b.first][b.second];
    if ((tb - tw) % 2 == 0 || tw < t) {
      cout << "WHITE" << endl;
      my = w;
      enemy = b;
      goforit(W);
    } else {
      cout << "BLACK" << endl;
      cin >> w.first >> w.second;
      my = b;
      enemy = w;
      goforit(W);
      goforit(B);
    }
  } else if (tw > tb) {
    assert(tw - tb == 2);
    int t = B[w.first][w.second];
    if (tb - (t - 1) >= 0) {
      cout << "WHITE" << endl;
      my = w;
      enemy = b;
      goforit(B);
      goforit(W);
    } else {
      cout << "BLACK" << endl;
      cin >> w.first >> w.second;
      my = b;
      enemy = w;
      goforit(B);
    }
  } else {
    assert(tb - tw == 1);
    int t = W[b.first][b.second];
    if (tw - 1 - (t - 1) >= 0) {
      cout << "BLACK" << endl;
      cin >> w.first >> w.second;
      my = b;
      enemy = w;
      goforit(W);
      goforit(B);
    } else {
      cout << "WHITE" << endl;
      my = w;
      enemy = b;
      goforit(W);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
