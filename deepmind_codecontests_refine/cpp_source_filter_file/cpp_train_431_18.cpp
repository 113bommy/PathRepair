#include <bits/stdc++.h>
using namespace std;
template <class T>
T cdiv(T num, T den) {
  return (num / den) + (num % den > 0);
}
template <typename TH>
void _dbg(const char* sdbg, TH h) {
  cerr << sdbg << "=" << h << "\n";
}
template <typename TH, typename... TA>
void _dbg(const char* sdbg, TH h, TA... t) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << "=" << h << ",";
  _dbg(sdbg + 1, t...);
}
template <class t>
t mag(t a) {
  return a > 0 ? a : -a;
}
std::ifstream term("/dev/tty");
string tempstring;
int tc = 1;
int n, m;
vector<int> vis(1000001);
class edge {
 public:
  int i, x, y;
};
vector<edge> vec(1000001);
int escape() {
  cin >> n >> m;
  vis.assign(3 * n + 1, 0);
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    vec[i] = {i, x, y};
  }
  int cnt = 0;
  vector<int> edno;
  for (int i = 1; i <= m; i++) {
    if (vis[vec[i].x] + vis[vec[i].y] == 0) {
      cnt++;
      vis[vec[i].x] = vis[vec[i].y] = 1;
      edno.push_back(i);
    }
  }
  if (cnt >= n) {
    cout << "Matching\n";
    for (int i = 0; i < n; i++) {
      cout << edno[i] << ' ';
    }
    cout << '\n';
    return 0;
  }
  cout << "Indset\n";
  cnt = 0;
  for (int i = 1; i <= 3 * n; i++) {
    if (vis[i] == 0) {
      cnt++;
      cout << i << ' ';
      if (cnt == n) {
        cout << '\n';
        return 0;
      }
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> tc;
  while (tc--) escape();
}
