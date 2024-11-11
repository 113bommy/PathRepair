#include <bits/stdc++.h>
using namespace std;
bool u[200001] = {false};
vector<int> vec[200001];
int k, ans = 0;
int fr[200001] = {0};
int dfs(int par, int curr) {
  int n, i;
  vector<int>::iterator it, itEnd;
  itEnd = vec[curr].end();
  for (it = vec[curr].begin(); it != itEnd; it++) {
    int ch = *it;
    if (ch == par) continue;
    fr[curr] += dfs(curr, ch);
  }
  if (u[curr]) fr[curr]++;
  int out = k - fr[curr];
  if (fr[curr] > out) {
    int red = fr[curr] - out;
    fr[curr] -= (red = ((red % 2 == 0) ? red : red + 1));
    k -= red;
  }
  ans += fr[curr];
  return fr[curr];
}
int main() {
  int n, i, j, v1, v2;
  cin >> n >> k;
  k *= 2;
  for (i = 0; i < k; i++) {
    cin >> j;
    u[j] = true;
  }
  for (i = 1; i < n; i++) {
    cin >> v1 >> v2;
    vec[v1].push_back(v2);
    vec[v2].push_back(v1);
  }
  dfs(1, 1);
  cout << ans << endl;
  return 0;
}
