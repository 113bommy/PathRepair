#include <bits/stdc++.h>
using namespace std;
void sb() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  long ans = 1;
  for (int i = 0; i < m; i++) {
    vector<int> visited(26, 0);
    long count = 0;
    for (int j = 0; j < n; j++) {
      if (!visited[v[j][i] - 'A']) {
        count++;
        visited[v[j][i] - 'A'] = 1;
      }
    }
    ans = ((ans % 1000000007) * count) % 1000000007;
    ans = ans % 1000000007;
  }
  cout << ans << endl;
}
