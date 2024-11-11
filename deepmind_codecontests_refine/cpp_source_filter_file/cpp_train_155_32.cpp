#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const int mod = (int)1e9 + 7;
const int N = 1e5 + 10;
const long long inf = -1e10;
const int maxm = 53;
vector<vector<char>> matrix(maxm, vector<char>(maxm));
vector<vector<int>> vt(maxm, vector<int>(maxm));
struct event {
  int x, y, size;
};
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
struct myComp {
  constexpr bool operator()(pair<int, int> const& a,
                            pair<int, int> const& b) const noexcept {
    return a.first < b.first;
  }
};
void solve() {
  int n, k;
  cin >> n >> k;
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  if (k < n + 1) {
    cout << -1;
    return;
  }
  set<int> s;
  for (int i = 0; i < n; i++) s.insert(i + 1);
  s.erase(a), s.erase(b), s.erase(c), s.erase(d);
  cout << a << " " << c << " ";
  for (auto it : s) cout << it << " ";
  cout << d << " " << b << "\n";
  cout << c << " " << a << " ";
  for (auto it : s) cout << it << " ";
  cout << b << " " << d << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
