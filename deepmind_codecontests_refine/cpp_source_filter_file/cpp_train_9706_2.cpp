#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
const long long N = 1e6 + 5;
const long long mod = 998244353;
const long long INF = 0x7f7f7f7f7f7f7f7f;
const int INFi = 0x7f7f7f7f;
long long test = 1, n, a[N], spf[N], ct[N], par[N];
vector<long long> adj[N];
void sieve() {
  memset(spf, -1, sizeof(spf));
  for (long long i = 2; i * i < N; i++) {
    if (spf[i] == -1) {
      for (int j = 2 * i; j < N; j += i) {
        if (spf[j] == -1) spf[j] = i;
      }
    }
  }
}
long long normalize(long long n) {
  for (int i = 2; i * i <= n; i++) {
    long long x = i * i;
    while (n % x == 0) n /= x;
  }
  return n;
}
long long bfs(long long st) {
  memset(ct, 0, sizeof(ct));
  memset(par, 0, sizeof(par));
  queue<long long> q;
  q.push(st);
  ct[st] = 1;
  while (q.size()) {
    long long x = q.front();
    q.pop();
    for (auto it : adj[x]) {
      if (it == par[x]) continue;
      if (ct[it] != 0) {
        return ct[x] + 1;
      }
      ct[it] = ct[x] + 1;
      par[it] = x;
      q.push(it);
    }
  }
  return INF;
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = normalize(a[i]);
  }
  sort(a, a + n);
  if (a[0] == 1) {
    cout << 1 << "\n";
    return;
  }
  a[n] = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == a[i + 1]) {
      cout << 2 << "\n";
      return;
    }
    if (spf[a[i]] == -1) {
      adj[1].push_back(a[i]);
      adj[a[i]].push_back(1);
    } else {
      long long x = spf[a[i]], y = a[i] / x;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
  }
  long long ans = INF;
  for (int i = 2; i * i <= N; i++) {
    if (spf[i] == -1) {
      ans = min(ans, bfs(i));
    }
  }
  if (ans == INF) ans = -1;
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(10);
  ;
  sieve();
  for (int i = 1; i <= test; i++) {
    solve();
  }
}
