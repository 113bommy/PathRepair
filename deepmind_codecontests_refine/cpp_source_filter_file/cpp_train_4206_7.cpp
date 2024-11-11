#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
using namespace std;
int n, m;
string s;
vector<int> v[305], ans;
int prime(int x) {
  if (x == 1) return 0;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
int check(int x, int y) {
  if (x > n || x < 1 || y >= m || y < 0) return 0;
  return 1;
}
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int dfs(int x, int y, int last) {
  if (x == y) return 1;
  for (int i = 0; i < v[x].size(); i++) {
    if (v[x][i] == last) continue;
    if (dfs(v[x][i], y, x)) {
      ans.push_back(x);
      return 1;
    }
  }
  return 0;
}
int main() {
  cin >> n;
  int a, b;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  int x, y;
  y = 1;
  ans.push_back(1);
  while (cin >> x) {
    dfs(x, y, 0);
    y = x;
  }
  dfs(1, y, 0);
  if (ans.size() != 2 * n - 1)
    cout << -1;
  else {
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  }
  return 0;
}
