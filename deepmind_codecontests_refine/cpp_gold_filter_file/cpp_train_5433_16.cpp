#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 41;
int in = 18, out;
int N;
vector<vector<int> > graph(MX);
int cc = 0;
bool bi = true;
void ff() {
  int col[N];
  for (int i = 0; i < (N); i++) col[i] = -1;
  for (int r = 0; r < (N); r++) {
    if (col[r] != -1) continue;
    col[r] = 0;
    queue<int> q;
    q.push(r);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (auto& a : graph[cur]) {
        if (col[a] != -1) {
          if (col[a] == col[cur]) bi = false;
        } else {
          col[a] = 1 - col[cur];
          q.push(a);
        }
      }
    }
    cc++;
  }
}
long long cis() {
  long long mask[N];
  for (int i = 0; i < (N); i++) {
    mask[i] = 1ll << N;
    mask[i]--;
    for (auto& a : graph[i]) {
      mask[i] -= 1ll << a;
    }
  }
  long long dp[(1ll << out)];
  for (int m = 0; m < ((1ll << out)); m++) {
    long long cm = 1ll << N;
    cm--;
    for (int i = 0; i < (out); i++) {
      if (m & (1ll << i)) cm &= mask[i + in];
    }
    bool good = true;
    for (int i = 0; i < (out); i++) {
      if ((m & (1ll << i)) && !(cm & (1ll << (i + in)))) good = false;
    }
    dp[m] = 0;
    if (good) dp[m] = 1ll;
  }
  for (int i = 0; i < (out); i++)
    for (int m = 0; m < ((1ll << out)); m++)
      if (m & (1ll << i)) dp[m] += dp[m ^ (1ll << i)];
  long long ans = 0;
  for (int m = 0; m < ((1ll << in)); m++) {
    long long cm = 1ll << N;
    cm--;
    for (int i = 0; i < (in); i++) {
      if (m & (1ll << i)) cm &= mask[i];
    }
    bool good = true;
    for (int i = 0; i < (in); i++) {
      if ((m & (1ll << i)) && !(cm & (1ll << (i)))) good = false;
    }
    if (good) {
      ans += dp[cm >> in];
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  int M;
  cin >> M;
  vector<pair<int, int> > edges;
  bool found[N];
  for (int i = 0; i < (N); i++) found[i] = false;
  for (int i = 0; i < (M); i++) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    edges.push_back({A, B});
    found[A] = true;
    found[B] = true;
  }
  int ind[N];
  int nxt = 0;
  long long mul = 1;
  for (int i = 0; i < (N); i++) {
    if (found[i]) {
      ind[i] = nxt;
      nxt++;
    } else {
      mul *= 2;
    }
  }
  N = nxt;
  ckmin(in, N);
  out = N - in;
  if (M == 0) {
    cout << 0 << nl;
    return 0;
  }
  for (int i = 0; i < (M); i++) {
    int A = edges[i].first;
    int B = edges[i].second;
    A = ind[A];
    B = ind[B];
    graph[A].push_back(B);
    graph[B].push_back(A);
  }
  ff();
  long long is = cis();
  long long ans = (1ll << N);
  ans -= 2 * is;
  if (!bi) ans -= (1ll << cc);
  ans += 2;
  cout << ans * mul << nl;
  return 0;
}
