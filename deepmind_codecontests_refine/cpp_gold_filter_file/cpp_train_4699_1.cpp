#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-10;
long long get_rand() {
  long long a = rand(), ft = 31, b = rand();
  return (a << ft) ^ b;
}
int gcd(int a, int b) {
  while (a && b) {
    a %= b;
    swap(a, b);
  }
  return a + b;
}
const int M = 1000000007;
long long cnt[10];
char f[1002][1002];
int str[10];
vector<queue<pair<pair<int, int>, pair<int, int> > > > vec;
int n, m;
void bfs() {
  bool cond = true;
  while (cond) {
    cond = false;
    for (int j = 0; j < vec.size(); j++) {
      if (vec[j].empty()) continue;
      int t = vec[j].front().second.second;
      while (!vec[j].empty() && vec[j].front().second.second == t) {
        ++cnt[j];
        auto p = vec[j].front();
        vec[j].pop();
        int x = p.first.first;
        int y = p.first.second;
        int d = p.second.first;
        if (x && f[x - 1][y] == '.') {
          f[x - 1][y] = '0' + j;
          if (d > 1)
            vec[j].push({{x - 1, y}, {d - 1, t}});
          else
            vec[j].push({{x - 1, y}, {str[j], t + 1}});
        }
        if (y && f[x][y - 1] == '.') {
          f[x][y - 1] = '0' + j;
          if (d > 1)
            vec[j].push({{x, y - 1}, {d - 1, t}});
          else
            vec[j].push({{x, y - 1}, {str[j], t + 1}});
        }
        if (x < n - 1 && f[x + 1][y] == '.') {
          f[x + 1][y] = '0' + j;
          if (d > 1)
            vec[j].push({{x + 1, y}, {d - 1, t}});
          else
            vec[j].push({{x + 1, y}, {str[j], t + 1}});
        }
        if (y < m - 1 && f[x][y + 1] == '.') {
          f[x][y + 1] = '0' + j;
          if (d > 1)
            vec[j].push({{x, y + 1}, {d - 1, t}});
          else
            vec[j].push({{x, y + 1}, {str[j], t + 1}});
        }
      }
      if (!vec[j].empty()) cond = true;
    }
  }
}
int main() {
  int p;
  cin >> n >> m >> p;
  for (int j = 1; j <= p; j++) cin >> str[j];
  vec.resize(p + 1);
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < m; i++) {
      cin >> f[j][i];
      if (f[j][i] >= '0' && f[j][i] <= '9') {
        vec[f[j][i] - '0'].push({{j, i}, {str[f[j][i] - '0'], 0}});
      }
    }
  }
  bfs();
  for (int j = 1; j <= p; j++) {
    cout << cnt[j] << ' ';
  }
}
