#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void ran() { srand(chrono::steady_clock::now().time_since_epoch().count()); }
long long get_rand() {
  long long a = rand();
  long long b = rand();
  return a * (RAND_MAX + 1ll) + b;
}
void usaco() {
  freopen("problem.in", "r", stdin);
  freopen("problem.out", "w", stdout);
}
template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
int n, m;
const int MXN = 6005;
int px[MXN], py[MXN];
inline int gcd(int a, int b) {
  a = abs(a), b = abs(b);
  return (a % 2 || b % 2);
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> px[i] >> py[i];
    px[i] /= 2;
    py[i] /= 2;
  }
  int ans = 0;
  int by[2][2];
  memset(by, 0, sizeof by);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int ij = gcd(px[i] - px[j], py[i] - py[j]);
      for (int a = 0; a < 2; a++)
        for (int b = 0; b < 2; b++) {
          if ((ij + gcd(px[i] - a, py[i] - b) + gcd(px[j] - a, py[j] - b)) %
                  2 ==
              0) {
            ans += by[a][b];
          }
        }
    }
    by[px[i] % 2][py[i] % 2]++;
  }
  cout << ans << '\n';
}
signed main() {
  ran();
  fast();
  int t = 1;
  while (t--) solve();
}
