#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e6 + 8;
int N, M, K, Q;
int g[25];
bool conn[1 << 22];
vector<int> ans;
void preprocess() {}
int solution() {
  if (N * (N - 1) == 2 * M) return 0;
  ans.clear();
  for (int i = 0; i < N; i++) {
    if (g[i] + (1 << i) == (1 << N) - 1) {
      ans.emplace_back(i);
      return 1;
    }
  }
  for (int i = 1; i < (1 << N); i++) {
    if (__builtin_popcount(i) == 1) {
      conn[i] = true;
      continue;
    }
    for (int j = 0; j < N; j++) {
      if ((i & (1 << j)) && conn[i ^ (1 << j)]) {
        if (g[j] & i) {
          conn[i] = true;
          break;
        }
      }
    }
  }
  int quanti = 100;
  for (int i = 1; i < (1 << N); i++) {
    bool ok = true;
    for (int j = 0; j < N; j++) {
      if (!(g[j] & i)) {
        ok = false;
        break;
      }
    }
    if (ok && conn[i] && __builtin_popcount(i) < quanti) {
      quanti = __builtin_popcount(i);
      ans.clear();
      for (int j = 0; j < N; j++) {
        if (i & (1 << j)) ans.emplace_back(j + 1);
      }
    }
  }
  return ans.size();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  while (cin >> N >> M) {
    int a, b;
    for (int i = 0; i < M; i++) {
      cin >> a >> b;
      g[a - 1] |= (1 << (b - 1));
      g[b - 1] |= (1 << (a - 1));
    }
    cout << solution() << '\n';
    for (int d : ans) {
      cout << d << ' ';
    }
    cout << '\n';
  }
  return 0;
}
