#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int mxN = 55;
bool can[mxN][mxN];
bool vis[mxN][mxN];
long long A[mxN];
long long cur;
int K, N;
bool solve(int st, int sh) {
  if (sh == K && st == N) return true;
  if (sh >= K || st >= N) return false;
  if (vis[st][sh]) return can[st][sh];
  can[st][sh] = false;
  long long with = 0;
  for (int i = st; i < N && !can[st][sh]; i++) {
    with += A[i];
    if ((with & cur) == cur) can[st][sh] = solve(i + 1, sh + 1);
  }
  vis[st][sh] = true;
  return can[st][sh];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> A[i];
  if (K == 1) {
    long long s = 0;
    for (int i = 0; i < N; i++) s += A[i];
    cout << s << '\n';
    return 0;
  }
  if (K == N) {
    long long s = A[0];
    for (int i = 1; i < N; i++) s &= A[i];
    cout << s << '\n';
    return 0;
  }
  long long res = 0;
  for (long long i = 60; i >= 0; i--) {
    cur = res | (1ll << i);
    memset(vis, 0, sizeof vis);
    if (solve(0, 0)) res = cur;
  }
  cout << res << '\n';
  return 0;
}
