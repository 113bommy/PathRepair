#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = (int)2e18 + 100;
const int INFint = 2047483647;
const int MAX = 1e5 + 100;
void solve();
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  solve();
  return 0;
}
int colors[MAX], v[MAX];
void solve() {
  int n, m;
  cin >> n >> m;
  long long sum = 0;
  for (int i = 0; i < m; ++i) {
    cin >> colors[i];
    sum += colors[i];
  }
  int ok = 1, last;
  for (int i = 1; i < m; ++i) {
    if (colors[i] > n - i) {
      ok = 0;
      break;
    }
  }
  if (sum < n || ok == 0) {
    cout << -1;
    exit(0);
  }
  ok = 0, last = 0;
  sum -= colors[0];
  int all = 0, pos = 1;
  cout << 1 << ' ';
  all += colors[0];
  for (int i = 1; i < m; ++i) {
    if (ok == 1 || sum == n - all) {
      pos = all;
      ok = 1;
      cout << pos + 1 << ' ';
      all += colors[i];
    } else {
      int x = max(0, pos + colors[i] - all);
      if (sum - colors[i] >= n - all - x) {
        pos += 1;
        all += x;
        sum -= colors[i];
        cout << pos << ' ';
      } else {
        ok = 1;
        int l = -1, r = colors[i] - x;
        while (l != r - 1) {
          int bet = (l + r) / 2;
          if (sum - colors[i] >= n - (all + colors[i] - bet)) {
            l = bet;
          } else {
            r = bet;
          }
        }
        pos = all - l + 1;
        cout << pos << ' ';
        ok = 1;
      }
    }
  }
}
