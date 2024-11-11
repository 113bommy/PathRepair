#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<pair<int, int>>> G;
vector<int> seen;
vector<int> ans;

void dfs(int v, int dist) {
  seen.at(v) = 1;
  ans.at(v) = dist % 2;
  // if (accumulate(seen.begin(), seen.end(), 0) == N) return;
  for (auto to : G.at(v)) {
    if (!seen.at(to.first)) dfs(to.first, dist + to.second);
  }
}

int main() {
  cin >> N;
  G.resize(N);
  seen.resize(N);
  ans.resize(N);
  for (int a, b, c; cin >> a >> b >> c;) {
    G.at(--a).push_back({--b, c % 2});
    G.at(b).push_back({a, c % 2});
  }
  dfs(0, 0);
  for (auto a : ans) cout << a << "\n";
}