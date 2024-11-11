#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
struct edge { int to, from, cost; };
int INF = 1000000000000;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, p;
  cin >> n >> m >> p;

  int a[m], b[m], c[m];
  for(int i = 0; i < m; i++) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
  }

  edge es[m];
  for(int i = 0; i < m; i++) {
    es[i] = (edge) { b[i], a[i], p - c[i]};
  }
  int d[n];
  for(int i = 0; i < n; i++) d[i] = INF;
  d[0] = 0;

  bool neg_loop = false;
  for(int i = 0; i < 2 * n; i++) {
    for(int j = 0; j < m; j++) {
      edge e = es[j];
      if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;
        if(i >= n - 1 && e.to == n - 1) {
          neg_loop = true;
          break;
        }
      }

    }
  }

  if(neg_loop) {
    cout << -1 << "\n";
    return 0;
  }


  cout << max(0LL, -d[n - 1]) << "\n";
  return 0;
}
