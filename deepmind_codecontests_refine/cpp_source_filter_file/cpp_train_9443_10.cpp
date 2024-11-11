#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000005;
const long long INFLL = 1000000000000000002ll;
const long long MOD = 1000000007;
inline long long min(long long a, long long b, long long c) {
  return min(min(a, b), c);
}
inline long long min(long long a, long long b, long long c, long long d) {
  return min(min(min(a, b), c), d);
}
inline long long max(long long a, long long b, long long c) {
  return max(max(a, b), c);
}
inline long long max(long long a, long long b, long long c, long long d) {
  return max(max(max(a, b), c), d);
}
bool V[55][55];
int N, K;
long long A[55], S[55][55];
vector<int> E[55];
bool ok(long long need) {
  for (int i = (0); i <= (50); i++) E[i].clear();
  for (int i = (0); i <= (N - 1); i++)
    for (int j = (i + 1); j <= (N); j++)
      if ((S[i + 1][j] & need) == need) E[i].push_back(j);
  for (int i = (0); i <= (50); i++)
    for (int k = (0); k <= (50); k++) V[i][k] = false;
  queue<pair<int, int> > q;
  V[0][0] = true;
  q.push({0, 0});
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    int n = p.first;
    int k = p.second;
    for (int v : E[n])
      if (!V[v][k + 1]) {
        V[v][k + 1] = true;
        q.push({v, k + 1});
      }
  }
  return V[N][K];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> N >> K;
  for (int i = (1); i <= (N); i++) cin >> A[i];
  for (int i = (1); i <= (N); i++)
    for (int j = (i); j <= (N); j++) S[i][j] = S[i][j - 1] + A[j];
  long long ans = 0;
  for (long long b = 50; b >= 0; b--) {
    long long want = ans | (1ll << b);
    if (ok(want)) ans = want;
  }
  cout << ans;
}
