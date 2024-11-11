#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
const long long INF = 1e18L + 5;
const int nax = 3e5 + 5;
struct S {
  long long score;
  pair<int, int> last_state;
  vector<int> moves;
};
bool done[nax][2];
S dp[nax][2];
int in[nax], memo[nax];
long long rec(int n, int anything) {
  if (n == 0) return 0;
  assert(n >= 1);
  if (done[n][anything]) return dp[n][anything].score;
  done[n][anything] = true;
  dp[n][anything].score = INF;
  if (anything) {
    rec(n, 0);
    dp[n][anything] = dp[n][0];
  }
  auto consider = [&](vector<int> moves) {
    int first = n;
    for (int x : moves) first = min(first, x);
    if (first < 1) return;
    for (int i = first; i <= n; ++i) in[i] = memo[i];
    long long cost = 0;
    for (int x : moves) {
      int here = min(in[x], in[x + 1]);
      if (here == 0) return;
      cost += here;
      in[x] -= here;
      in[x + 1] -= here;
    }
    if (!anything && in[n]) return;
    for (int i = first; i < n; ++i)
      if (in[i] && in[i + 1]) return;
    bool ple = in[first] == 0;
    cost += rec(first - 1, ple);
    if (cost < dp[n][anything].score) {
      dp[n][anything].score = cost;
      dp[n][anything].last_state = {first - 1, ple};
      dp[n][anything].moves = moves;
    }
  };
  consider({});
  for (int len = 1; len <= 3; ++len) {
    vector<int> moves(len);
    for (int i = 1; i <= len; ++i) moves[i - 1] = n - i;
    sort(moves.begin(), moves.end());
    do {
      consider(moves);
    } while (next_permutation(moves.begin(), moves.end()));
  }
  debug() << " ["
          << "n"
             ": "
          << (n)
          << "] "
             " ["
          << "anything"
             ": "
          << (anything)
          << "] "
             " ["
          << "dp[n][anything].score"
             ": "
          << (dp[n][anything].score) << "] ";
  if (anything) assert(dp[n][anything].score < INF);
  return dp[n][anything].score;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &in[i]);
    memo[i] = in[i];
  }
  vector<int> moves;
  rec(n, 1);
  pair<int, int> p{n, 1};
  while (p.first) {
    for (int x : dp[p.first][p.second].moves) moves.push_back(x);
    p = dp[p.first][p.second].last_state;
  }
  printf("%d\n", (int)moves.size());
  for (int x : moves) printf("%d\n", x);
}
