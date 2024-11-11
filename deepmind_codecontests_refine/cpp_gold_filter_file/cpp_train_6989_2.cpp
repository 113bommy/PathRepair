#include <bits/stdc++.h>
using namespace std;
void setup() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
}
const long long N = 55;
long long A[N][N];
bool used[N][N];
long long col[N][N];
vector<pair<long long, long long>> G[N][N];
long long mx[4] = {0, 0, -1, 1};
long long my[4] = {1, -1, 0, 0};
void dfs(pair<long long, long long> v, vector<pair<long long, long long>> &comp,
         long long color) {
  comp.push_back(v);
  used[v.first][v.second] = 1;
  col[v.first][v.second] = color;
  for (auto i : G[v.first][v.second]) {
    if (!used[i.first][i.second]) dfs(i, comp, color);
  }
}
signed main() {
  setup();
  long long k;
  cin >> k;
  bool ans = false;
  for (long long n = 2; n * 2 - 1 <= 2000; ++n) {
    long long c = (2 * n - 1 - (k % (2 * n - 1))) % (2 * n - 1);
    assert((k + c) % (2 * n - 1) == 0 && c >= 0 && c < 2 * n - 1);
    long long v = ((k + c) / (2 * n - 1) - c + n - 1 + 2 * n - 3) / (2 * n - 2);
    long long mx = c + (2 * n - 1) * v;
    long long a = (k + c) / (2 * n - 1) + v + n - 1;
    assert(mx >= a);
    if (mx >= 1e6) continue;
    cout << 2 * n - 1 << '\n';
    for (long long i = 0; i < n * 2 - 2; ++i) {
      if (i % 2 == 0)
        cout << mx << ' ';
      else
        cout << -mx - 1 << ' ';
    }
    cout << a << '\n';
    ans = true;
    break;
  }
  if (!ans) cout << -1 << '\n';
}
