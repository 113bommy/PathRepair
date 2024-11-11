#include <bits/stdc++.h>
using namespace std;
const int N = 10050;
int n;
vector<int> a[N];
map<pair<int, int>, int> E;
struct getAnswer {
  int x, y, id;
  double T;
  getAnswer(int x, int y, int id, double T) : x(x), y(y), id(id), T(T) {}
};
vector<getAnswer> ans;
void dfs(int v, int p = 0, double T = 0) {
  for (int i = 0, cnt = 1; i < (int)a[v].size(); ++i) {
    int to = a[v][i];
    if (to == p) continue;
    double now = (T + cnt * 2.0 / (int)a[v].size());
    while (now >= 2.0) now -= 2;
    ans.push_back(getAnswer(v, to, E[make_pair(v, to)], now));
    if (now <= 1) {
      dfs(to, v, now + 1);
    } else {
      dfs(to, v, now - 1);
    }
    ++cnt;
  }
}
int main() {
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
    E[make_pair(x, y)] = E[make_pair(y, x)] = i;
  }
  dfs(1);
  cout << n - 1 << endl;
  for (int i = 0; i < n - 1; ++i) {
    cout << "1 " << ans[i].id << " ";
    if (ans[i].T <= 1) {
      cout << ans[i].x << " " << ans[i].y << " " << ans[i].T << endl;
    } else {
      cout << ans[i].y << " " << ans[i].x << " " << ans[i].T - 1 << endl;
    }
  }
  return 0;
}
