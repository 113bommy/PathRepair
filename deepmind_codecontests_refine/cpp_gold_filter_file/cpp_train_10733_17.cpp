#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
void itval(istream_iterator<string> it) {}
template <typename T, typename... Args>
void itval(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  itval(++it, args...);
}
const long long int MOD = 1e9 + 7;
template <typename T>
inline void print(T x) {
  cout << x << "\n";
}
template <typename T>
inline void printvec(T x) {
  for (auto a : x) cout << a << ' ';
  cout << '\n';
}
struct custom {
  bool operator()(const pair<int, pair<int, int> > &p1,
                  const pair<int, pair<int, int> > &p2) const {
    return p1.first < p2.first;
  }
};
long long int get_pow(long long int a, long long int b, long long int M = MOD) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = (res * a) % M;
    a = (a * a) % M;
    b >>= 1;
  }
  return res;
}
const long long int N = 1e5 + 5, inf = 2e18;
std::vector<int> adj[1005];
set<int> A, B;
int n;
int bfs(int s) {
  vector<bool> vis(n + 1, false);
  queue<int> q;
  q.push(s);
  if (A.find(s) != A.end()) {
    return s;
  }
  while (!q.empty()) {
    auto t = q.front();
    q.pop();
    for (auto x : adj[t]) {
      if (!vis[x]) {
        vis[x] = 1;
        if (A.find(x) != A.end()) {
          return x;
        }
        q.push(x);
      }
    }
  }
  return -1;
}
void solve() {
  cin >> n;
  A.clear();
  B.clear();
  for (long long int i = (long long int)1; i < (long long int)(n + 1); i++) {
    adj[i].clear();
  }
  int x, y;
  for (long long int i = (long long int)1; i < (long long int)(n); i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int k;
  cin >> k;
  for (long long int i = (long long int)0; i < (long long int)(k); i++) {
    cin >> x;
    A.insert(x);
  }
  cin >> k;
  for (long long int i = (long long int)0; i < (long long int)(k); i++) {
    cin >> x;
    B.insert(x);
  }
  int s;
  cout << "B " << *B.begin() << endl;
  cin >> s;
  y = bfs(s);
  cout << "A " << y << endl;
  cin >> s;
  if (B.count(s)) {
    cout << "C " << y << endl;
    return;
  }
  cout << "C " << -1 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test = 1;
  cin >> test;
  clock_t z = clock();
  for (long long int tes = (long long int)0; tes < (long long int)(test);
       tes++) {
    solve();
  }
  fprintf(stderr, "Total Time:%.4f\n", (double)(clock() - z) / CLOCKS_PER_SEC),
      fflush(stderr);
  return 0;
}
