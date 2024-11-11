#include <bits/stdc++.h>
using std::abs;
using std::bitset;
using std::cerr;
using std::cin;
using std::cout;
using std::deque;
using std::make_tuple;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::queue;
using std::set;
using std::string;
using std::swap;
using std::tuple;
using std::unordered_map;
using std::unordered_set;
using std::vector;
struct init {
  init() {
    cin.tie(0);
    cout.tie(0);
    std::iostream::sync_with_stdio(0);
    cout << std::fixed << std::setprecision(10);
    cerr << std::fixed << std::setprecision(10);
    srand(std::chrono::duration_cast<std::chrono::nanoseconds>(
              std::chrono::high_resolution_clock::now().time_since_epoch())
              .count());
  }
} init;
const int MAXN = 50001, MAXT = 1e6 + 1;
vector<int> g[MAXN];
vector<int> possible[MAXN];
int team[MAXN];
int c[MAXT];
int main() {
  int n, e;
  cin >> n >> e;
  for (int i = 0; i < e; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    int l;
    cin >> l;
    possible[i].resize(l);
    for (int& j : possible[i]) {
      cin >> j;
      mx = max(mx, j);
    }
  }
  while (true) {
    set<int> used;
    for (int i = 1; i <= n; ++i) {
      team[i] = possible[i][rand() % possible[i].size()];
      used.insert(team[i]);
    }
    for (int t : used) c[t] = rand() & 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
      for (int to : g[i])
        if (c[team[i]] != c[team[to]]) ++ans;
    if (ans >= e) {
      for (int i = 1; i <= n; ++i) cout << team[i] << ' ';
      cout << '\n';
      for (int i = 1; i <= mx; ++i) cout << c[i] + 1 << ' ';
      cout << '\n';
      return 0;
    }
  }
  return 0;
}
