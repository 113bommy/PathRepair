#include <bits/stdc++.h>
using namespace std;
const long double pai = acos(-1.0L);
const long double eps = 1e-10;
const long long mod = 1e9 + 7;
const int MXN = 1e6 + 5;
int a[MXN];
vector<int> dv[MXN], g[MXN];
void divfj(long long x, int ii) {
  long long i = 2;
  for (; i * i <= x; i++) {
    if (x % i == 0) {
      while (x % i == 0) x /= i, dv[ii].push_back(i);
    }
  }
  if (x != 1) dv[ii].push_back(x);
}
int h[MXN], pr[MXN];
int bfs(int start) {
  queue<int> q;
  memset(h, 0, sizeof(h));
  memset(pr, 0, sizeof(pr));
  h[start] = 1;
  q.push(start);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (auto i : g[now]) {
      if (pr[now] == i) continue;
      if (h[i]) {
        return h[now] + h[i] - 1;
      }
      pr[i] = now, h[i] = h[now] + 1;
      q.push(i);
    }
  }
  return INT_MAX;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    divfj(a[i], i);
  }
  for (int i = 1; i <= n; i++) {
    map<int, int> ma;
    for (auto j : dv[i]) ma[j]++;
    for (auto &j : ma) j.second %= 2;
    dv[i].clear();
    for (auto j : ma) {
      if (j.second) dv[i].push_back(j.first);
    }
  }
  for (int i = 1; i <= n; i++) {
    if ((int)dv[i].size() == 0) {
      puts("1");
      return 0;
    }
  }
  set<vector<int> > st;
  for (int i = 1; i <= n; i++) {
    if (st.find(dv[i]) != st.end()) return puts("2"), 0;
    st.insert(dv[i]);
  }
  for (int i = 1; i <= n; i++) {
    if ((int)dv[i].size() == 1) {
      g[dv[i][0]].push_back(1);
      g[1].push_back(dv[i][0]);
    }
    if ((int)dv[i].size() == 2) {
      g[dv[i][1]].push_back(dv[i][0]);
      g[dv[i][0]].push_back(dv[i][1]);
    }
  }
  int ans = INT_MAX;
  for (int i = 1; i <= 1e3; i++) {
    ans = min(ans, bfs(i));
  }
  if (ans == INT_MAX)
    puts("-1");
  else
    cout << ans << '\n';
  return 0;
}
