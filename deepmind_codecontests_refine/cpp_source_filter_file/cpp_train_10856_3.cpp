#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INF64 = 3e18 + 1;
const char invdir[]{'L', 'U', 'R', 'D'};
const char dir[]{'R', 'D', 'L', 'U'};
const int dx[]{0, 1, 0, -1};
const int dy[]{1, 0, -1, 0};
unsigned get_seed() {
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  return seed;
}
const int MOD = 1000000007;
const int NMAX = 1000000;
using namespace std;
int ans[100555];
int solve() {
  int n;
  cin >> n;
  bool q = 1;
  int plus = 0;
  int prevv = 0;
  stack<int> S;
  int k = 0;
  vector<int> commands;
  for (int i = 1; i <= 2 * n; ++i) {
    char ch;
    cin >> ch;
    if (ch == '+') {
      plus++;
      S.push(++k);
      prevv = 0;
      commands.push_back(0);
    } else {
      int v;
      cin >> v;
      commands.push_back(v);
      plus--;
      if (plus < 0) {
        q = 0;
      }
      if (v < prevv) {
        q = 0;
      }
      if (q) {
        int pos = S.top();
        S.pop();
        ans[pos] = v;
        prevv = v;
      }
    }
  }
  if (q) {
    int i = 0;
    set<int> ss;
    for (auto el : commands) {
      if (el == 0) {
        ss.insert(ans[++i]);
      } else {
        int bot = *ss.rbegin();
        if (bot != el) {
          q = 0;
        }
        ss.erase(*ss.rbegin());
      }
    }
  }
  if (q) {
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
      cout << ans[i] << " ";
    }
  } else {
    cout << "NO\n";
  }
  return 0;
}
int main() {
  cout << setprecision(16);
  cin.tie(0);
  std::ios_base::sync_with_stdio(0);
  int T = 1;
  int i = 1;
  while (T--) {
    i++;
    solve();
  }
  return 0;
}
