#include <bits/stdc++.h>
const int MAXN = 1e5 + 5;
int N, M;
int A[MAXN], cntN;
std::vector<int> G[MAXN];
std::map<std::string, int> Str;
std::vector<std::pair<int, int> > Q[MAXN];
int Sz[MAXN], Son[MAXN], Dep[MAXN];
void getSon(int x) {
  Sz[x] = 1;
  for (auto v : G[x]) {
    Dep[v] = Dep[x] + 1;
    getSon(v);
    Sz[x] += Sz[v];
    if (Sz[v] > Sz[Son[x]]) {
      Son[x] = v;
    }
  }
}
int Ans[MAXN];
int skip;
std::multiset<int> S[MAXN];
int Cnt[MAXN];
void add(int x, int val) {
  if (val == 1) {
    if (S[Dep[x]].find(A[x]) == S[Dep[x]].end()) {
      ++Cnt[Dep[x]];
    }
    S[Dep[x]].insert(A[x]);
  } else {
    S[Dep[x]].erase(S[Dep[x]].find(A[x]));
    if (S[Dep[x]].find(A[x]) == S[Dep[x]].end()) {
      --Cnt[Dep[x]];
    }
  }
  for (auto v : G[x]) {
    if (v != skip) {
      add(v, val);
    }
  }
}
void dfs(int x, bool keep) {
  for (auto v : G[x]) {
    if (v != Son[x]) {
      dfs(v, 0);
    }
  }
  if (Son[x]) {
    dfs(Son[x], 1);
    skip = Son[x];
  }
  add(x, 1);
  for (auto v : Q[x]) {
    Ans[v.second] = Cnt[Dep[x] + v.first];
  }
  skip = 0;
  if (!keep) {
    add(x, -1);
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin >> N;
  int u, v;
  std::string name;
  for (int i = 1; i <= N; ++i) {
    std::cin >> name >> v;
    if (Str.find(name) == Str.end()) {
      Str[name] = ++cntN;
    }
    A[i] = Str[name];
    G[v].push_back(i);
  }
  std::cin >> M;
  for (int i = 1; i <= M; ++i) {
    std::cin >> u >> v;
    Q[u].push_back(std::make_pair(v, i));
  }
  getSon(0);
  dfs(0, 1);
  for (int i = 1; i <= M; ++i) {
    std::cout << Ans[i] << "\n";
  }
  return 0;
}
