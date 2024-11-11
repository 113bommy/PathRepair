#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
int n, k;
int u[N], d[N], s[N];
vector<vector<int>> cnt;
vector<int> g[N];
long long current = 0;
long long ans = 0;
void dfs(int v) {
  if (u[v]) return;
  u[v] = s[v] = 1;
  for (auto i : g[v]) {
    if (!u[i]) {
      d[i] = d[v] + 1;
      dfs(i);
      cnt[v][1]++;
      for (int j = 0; j < k; ++j) {
        cnt[v][(j + 1) % k] += cnt[i][j];
      }
      s[v] += s[i];
    }
  }
}
void calc(int v, long long current, vector<int> another) {
  if (u[v]) return;
  ans += current;
  u[v] = 1;
  vector<int> kek = another;
  for (int i = 0; i < k; ++i) {
    another[(i + 1) % k] = kek[i];
  }
  ++another[1 % k];
  for (auto i : g[v]) {
    if (!u[i]) {
      ++another[2 % k];
      for (int j = 0; j < k; ++j) {
        another[(j + 2) % k] += cnt[i][j];
      }
    }
  }
  for (auto i : g[v]) {
    if (!u[i]) {
      long long ncur = current;
      ncur -= cnt[i][0] + 1;
      --another[2 % k];
      for (int j = 0; j < k; ++j) {
        another[(j + 2) % k] -= cnt[i][j];
      }
      if (k == 1)
        ncur += another[0];
      else
        ncur += another[1];
      calc(i, ncur, another);
      ++another[2 % k];
      for (int j = 0; j < k; ++j) {
        another[(j + 2) % k] += cnt[i][j];
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cnt.resize(N, vector<int>(5));
  cin >> n >> k;
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1);
  for (int i = 1; i <= n; ++i) {
    u[i] = 0;
    current += (d[i] / k + (d[i] % k != 0));
  }
  vector<int> a = {0, 0, 0, 0, 0};
  calc(1, current, a);
  cout << ans / 2LL << '\n';
}
