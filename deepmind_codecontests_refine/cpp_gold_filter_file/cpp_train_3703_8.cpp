#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
string a, b, c;
int q, n, t;
int arr[1000009];
int brr[1000009];
set<int> adj[300007];
int d[1000008];
void dfs(int cur, int col, int p = -1) {
  d[cur] = col + 1;
  for (auto i : adj[cur]) {
    if (i - p && d[i] == 0) {
      dfs(i, 1 - col, cur);
    }
  }
}
vector<pair<int, int> > vec;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    vec.push_back(make_pair(x, y));
    adj[x].insert(y);
    adj[y].insert(x);
    adj[2 * i].insert(2 * i - 1);
    adj[2 * i - 1].insert(2 * i);
  }
  for (int i = 1; i <= 2 * n; i++)
    if (!d[i]) dfs(i, 1);
  for (auto k : vec) {
    cout << d[k.first] << " " << d[k.second];
    cout << "\n";
  }
}
