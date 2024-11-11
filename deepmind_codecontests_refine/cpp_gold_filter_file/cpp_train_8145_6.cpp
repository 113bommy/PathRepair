#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, a, b, len = -1;
vector<int> g[N], used(N, 0), H(N, 0), G(N, 0), dp(N, 0);
vector<int> snake;
int get_length(int v, int h) {
  used[v] = 1;
  if (v == b) {
    snake.push_back(b);
    len = h;
    return 1;
  }
  for (int k = 0; k < g[v].size(); k++) {
    int to = g[v][k];
    if (used[to] == 0) {
      int ind = get_length(to, h + 1);
      if (ind == 1) {
        snake.push_back(v);
        return ind;
      }
    }
  }
  return 0;
}
pair<int, int> sh[N + 1];
int msh[N + 1];
pair<int, int> mx(pair<int, int> a, int b) {
  if (b > a.first) {
    a.second = a.first;
    a.first = b;
  } else {
    if (b > a.second) a.second = b;
  }
  return a;
}
int DFS(int v, int p) {
  used[v] = 1;
  int depth = 1;
  for (int k = 0; k < g[v].size(); k++) {
    int to = g[v][k];
    if (used[to] == 0) depth = max(depth, DFS(to, v) + 1);
  }
  if (v != 1) {
    if (depth >= len - 1) G[p]++;
    sh[p] = mx(sh[p], depth);
  }
  dp[v] = depth;
  return depth;
}
void get_G(int v, int p) {
  used[v] = 1;
  if (v != 1) {
    msh[v] = msh[p] + 1;
    int depth = 0;
    if (sh[p].first != dp[v])
      depth = sh[p].first;
    else
      depth = sh[p].second;
    msh[v] = max(msh[v], depth + 2);
    if (msh[v] >= len) G[v]++;
  }
  for (int k = 0; k < g[v].size(); k++) {
    int to = g[v][k];
    if (used[to] == 0) get_G(to, v);
  }
}
int w[N], s[N];
void get_snake_array(int v, int p, int h) {
  used[v] = 1;
  s[p] = max(s[p], h);
  w[v] = p;
  for (int k = 0; k < g[v].size(); k++) {
    int to = g[v][k];
    if (used[to] == 0) {
      get_snake_array(to, p, h + 1);
    }
  }
}
int prefl[N], prefr[N];
int Q;
int main() {
  cin >> Q;
  while (Q--) {
    cin >> n >> a >> b;
    snake.resize(0);
    used.resize(0);
    used.resize(n + 1, 0);
    for (int k = 0; k <= n; k++) {
      prefl[k] = 0;
      prefr[k] = 0;
      w[k] = 0;
      s[k] = 0;
      msh[k] = 0;
      sh[k] = {0, 0};
      dp[k] = 0;
      H[k] = 0;
      G[k] = 0;
      g[k].resize(0);
      len = -1;
    }
    for (int k = 1; k < n; k++) {
      int first, second;
      cin >> first >> second;
      g[first].push_back(second);
      g[second].push_back(first);
    }
    get_length(a, 1);
    used.resize(0);
    used.resize(n + 1, 0);
    DFS(1, 0);
    used.resize(0);
    used.resize(n + 1, 0);
    get_G(1, 0);
    int cnt = 0;
    for (int k = 1; k <= n; k++) {
      if (G[k] >= 3) cnt++;
    }
    if (cnt == 0) {
      cout << "NO" << endl;
      continue;
    }
    used.resize(0);
    used.resize(n + 1, 0);
    int M = snake.size();
    for (int k = 0; k < snake.size(); k++) {
      used[snake[k]] = 1;
    }
    for (int k = 0; k < snake.size(); k++) {
      get_snake_array(snake[k], k, 0);
    }
    prefl[1] = s[1];
    for (int k = 2; k <= M; k++) prefl[k] = max(prefl[k - 1], s[k]);
    prefr[M] = s[M];
    for (int k = M - 1; k >= 1; k--) prefr[k] = max(prefr[k + 1], s[k]);
    int l = 0, r = len - 1;
    int L = s[r], R = r - s[l];
    while (l < r) {
      if (l < L) {
        l++;
        R = min(R, len - 1 - (s[l] - l));
      } else if (r > R) {
        r--;
        L = max(L, s[r] - (len - 1 - r));
      } else
        break;
    }
    if (l == r)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
