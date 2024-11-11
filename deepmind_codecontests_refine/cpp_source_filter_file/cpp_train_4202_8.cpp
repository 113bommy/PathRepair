#include <bits/stdc++.h>
using namespace std;
const int M = 5e6 + 5;
const long long int mod = 1e9 + 7;
const long long int inf = 9e18;
const double pi = 3.14159265358979323846;
long long int P[10000005] = {0};
long long int raised(long long int x, long long int v) {
  if (v == 0) return 1 % mod;
  if (v % 2 == 1) return (x * raised(x, v - 1)) % mod;
  long long int r = raised(x, v / 2);
  return (r * r) % mod;
}
bool prime(long long int n) {
  if (n == 1) return 1;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return 0;
  return 1;
}
long long int hcf(long long int a, long long int b) {
  if (a % b == 0) return b;
  return hcf(b, a % b);
}
void DFS(bool vis[], vector<int> adj[], int a) {
  vis[a] = 1;
  for (int i = 0; i < adj[a].size(); i++) {
    if (!vis[adj[a][i]]) {
      DFS(vis, adj, adj[a][i]);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int c = -1, x, y, z, a, b, m;
  cin >> a >> b >> m >> x >> y >> z;
  double t = (double)m / (-y);
  double d;
  d = x * t;
  if (((int)d / a) % 2) c = 1;
  d -= ((int)d / a) * a;
  if (c == -1)
    printf("%.15f ", abs((double)a - abs((double)a / 2 - d)));
  else
    printf("%.15f", abs((double)a / 2 - d));
  d = z * t;
  c = -1;
  if (((int)d / b) % 2) c = 1;
  d -= ((int)d / b) * b;
  if (c == -1)
    printf("%.15f", d);
  else
    printf("%.15f", (double)b - d);
}
