#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000001;
long long a[200000], b[6];
struct mn {
  long long a, b;
};
long long r = 0;
vector<mn> v[100001];
long long dist[200000];
void dfs(long long s, int p, long long d) {
  if (d > a[s]) return;
  r++;
  for (int i = 0; i < v[s].size(); i++) {
    long long k = v[s][i].a;
    if (k != p) {
      dfs(k, s, max(d + v[s][i].b, 0ll));
    }
  }
}
int main() {
  int m, n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n - 1; i++) {
    long long x, y;
    cin >> x >> y;
    v[i + 1].push_back({x, y});
    v[x].push_back({i + 1, y});
  }
  dfs(1, 1, 0);
  cout << n - r << endl;
}
