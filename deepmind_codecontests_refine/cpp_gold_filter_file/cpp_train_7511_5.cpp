#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 10;
const int N = (int)1e6 + 10;
const long double eps = 1e-7;
mt19937 rnd(228);
int main() {
  int n, q;
  cin >> n >> q;
  deque<int> d;
  int mn = INF;
  int mx = -INF;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    d.push_back(x);
    mn = min(mn, x);
    mx = max(mx, x);
  }
  vector<pair<int, int>> ans(N);
  for (int iter = 1; iter < N; ++iter) {
    int a = d.front();
    d.pop_front();
    int b = d.front();
    ans[iter] = make_pair(a, b);
    d.pop_front();
    d.push_front(max(a, b));
    d.push_back(min(a, b));
  }
  int st = -1;
  for (int i = N / 2 - 1; i >= 1; --i) {
    if (ans[i] == pair<int, int>({mx, mn})) {
      st = i;
      break;
    }
  }
  for (int i = 1; i <= q; ++i) {
    long long m;
    cin >> m;
    if (m < N) {
      cout << ans[m].first << ' ' << ans[m].second << '\n';
      continue;
    }
    m -= st;
    m %= (n - 1);
    cout << ans[st + m].first << ' ' << ans[st + m].second << '\n';
  }
}
