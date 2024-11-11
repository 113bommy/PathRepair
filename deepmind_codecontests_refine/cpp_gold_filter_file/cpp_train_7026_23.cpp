#include <bits/stdc++.h>
using namespace std;
long long int relation[9999] = {0};
struct ans1 {
  long long int a, b;
};
int main() {
  ios::sync_with_stdio(0);
  long long int n, m, a, b;
  cin >> n >> m;
  long long int edge[n + 2][n + 2];
  struct ans1 sol[m + 1];
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    edge[a][b] = 1;
    edge[b][a] = 1;
    relation[a]++;
    relation[b]++;
    sol[i].a = a;
    sol[i].b = b;
  }
  long long int ans = 1000000009;
  for (int k = 0; k < m; k++) {
    long long int fir = sol[k].a;
    long long int sec = sol[k].b;
    for (int i = 1; i <= n; i++) {
      if (i != fir && i != sec) {
        if (edge[fir][i] == 1 && edge[i][sec] == 1) {
          ans = min(ans, relation[fir] + relation[i] + relation[sec] - 6);
        }
      }
    }
  }
  if (ans == 1000000009) {
    cout << -1;
  } else
    cout << ans;
  return 0;
}
