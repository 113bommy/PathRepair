#include <bits/stdc++.h>
using namespace std;
const long long size = 1e6 + 7;
const long long mod = 1e9 + 7;
vector<long long> adj[size];
long long vis[size];
long long arr[size];
long long cost[size];
long long name[size];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> cost[i];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i]--;
    name[i] = i;
  }
  memset(vis, 0, sizeof(vis));
  set<long long> K;
  for (long long i = 0; i < n; i++) {
    if (vis[i] == 1) continue;
    set<long long> S;
    long long x = i;
    long long fl = 0;
    while (true) {
      S.insert(x);
      x = arr[i];
      if (vis[x] == 1) {
        K.insert(name[x]);
        for (auto p : S) {
          name[p] = name[x];
          vis[p] = 1;
        }
        break;
      }
      if (S.find(x) != S.end()) {
        fl = 1;
        K.insert(x);
        for (auto p : S) {
          name[p] = x;
          vis[p] = 1;
        }
        break;
      }
    }
  }
  long long ans = 0;
  for (auto p : K) {
    long long mi = cost[p];
    long long st = arr[p];
    while (st != p) {
      mi = min(mi, cost[st]);
      st = arr[st];
    }
    ans = ans + mi;
  }
  cout << ans << endl;
}
