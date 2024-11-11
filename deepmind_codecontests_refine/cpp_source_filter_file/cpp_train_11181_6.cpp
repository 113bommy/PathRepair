#include <bits/stdc++.h>
using namespace std;
const int N = 26, MAX = 100001;
int dist[N][N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s, t;
  cin >> s >> t;
  int n;
  cin >> n;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      if (i != j) dist[i][j] = MAX;
  for (int i = 1; i <= n; ++i) {
    char u, v;
    cin >> u >> v;
    int z;
    cin >> z;
    dist[u - 'a'][v - 'a'] = min(dist[u - 'a'][v - 'a'], z);
  }
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      for (int k = 0; k < N; ++k)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  if (s.size() != t.size())
    cout << -1 << "\n";
  else {
    bool flag = true;
    int sum = 0;
    string ans;
    for (int i = 0; i < s.size(); ++i) {
      int u = s[i] - 'a', v = t[i] - 'a', k = MAX, p = -1;
      for (int j = 0; j < N; ++j) {
        if (dist[u][j] < MAX && dist[v][j] < MAX) {
          if (k > dist[u][j] + dist[v][j]) {
            k = dist[u][j] + dist[v][j];
            p = j;
          }
        }
      }
      if (k >= MAX) {
        flag = false;
        break;
      }
      ans.push_back(char(p + 'a'));
      sum += k;
    }
    if (flag)
      cout << sum << "\n" << ans << "\n";
    else
      cout << -1 << "\n";
  }
}
