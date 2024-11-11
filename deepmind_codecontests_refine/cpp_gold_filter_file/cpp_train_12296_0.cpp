#include <bits/stdc++.h>
using namespace std;
const int N = 55;
const int M = 2005;
vector<int> r(N, 0);
string c;
map<char, set<pair<int, int>>> rgb;
int state[N][M];
void dfs(int cur) {
  if (state[cur][0] != -1) return;
  char color = c[cur - 1];
  int num = r[cur - 1];
  for (int i = 0; i <= num; i += 1) state[cur][i] = 0;
  for (auto pr : rgb) {
    if (pr.first == color) continue;
    auto itr = pr.second.upper_bound({num, N});
    while (itr != pr.second.end()) {
      dfs(itr->second);
      for (int i = 0; i < M && state[itr->second][i] != -1; i += 1) {
        int key = min(M - 1, num + i);
        int dist = abs(cur - itr->second);
        if (state[cur][key] == -1 ||
            dist + state[itr->second][i] < state[cur][key])
          state[cur][key] = dist + state[itr->second][i];
      }
      itr++;
    }
  }
  for (int i = M - 2; i >= 0; i -= 1) {
    if (state[cur][i + 1] != -1) {
      if (state[cur][i] == -1 || state[cur][i + 1] < state[cur][i])
        state[cur][i] = state[cur][i + 1];
    }
  }
}
int main() {
  int n, k, s;
  cin >> n >> s >> k;
  for (int i = 0; i < n; i += 1) {
    cin >> r[i];
  }
  cin >> c;
  for (int i = 0; i < n; i += 1) {
    rgb[c[i]].insert({r[i], i + 1});
  }
  memset(state, -1, sizeof(state));
  for (auto pr : rgb) {
    if (pr.second.empty() == false) {
      dfs(pr.second.begin()->second);
    }
  }
  int ans = -1;
  for (int i = 1; i <= n; i += 1) {
    if (state[i][k] != -1) {
      if (ans == -1 || state[i][k] + abs(i - s) < ans)
        ans = state[i][k] + abs(i - s);
    }
  }
  cout << ans << endl;
}
