#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
long long power(long long x, long long y) {
  long long res = 1;
  x = x % 1000000007;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res;
}
map<long long, vector<long long>> adj;
map<long long, vector<long long>> connect;
map<long long, long long> visited;
long long a[200005], b[200005];
void dfs(long long curr, long long par) {
  visited[curr] = 1;
  a[curr] = 0;
  for (auto x : adj[curr]) {
    if (visited[x] != 1) {
      a[curr] += a[x];
      dfs(x, curr);
    }
  }
  a[curr] %= 2;
}
int main() {
  long long n;
  cin >> n;
  a[1] = 1;
  for (long long pa, i = 2; i <= n; i++) {
    cin >> pa;
    b[i] = b[pa] + 1;
    adj[pa].push_back(i);
    adj[i].push_back(pa);
    a[i] = 1;
  }
  long long lvl = 0;
  for (long long i = 0; i <= n; i++) lvl = max(lvl, b[i]);
  long long cnt = 0;
  map<long long, long long> bre;
  for (long long i = 0; i <= lvl; i++) {
    bre[i]++;
  }
  for (long long i = 0; i <= lvl; i++) {
    cnt += bre[i] % 2;
  }
  cout << cnt << endl;
  return 0;
}
