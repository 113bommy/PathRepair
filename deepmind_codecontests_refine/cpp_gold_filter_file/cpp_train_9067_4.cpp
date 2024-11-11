#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void debug(const char* name, Arg1&& arg1) {
  cerr << name << ": " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void debug(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " | ";
  debug(comma + 1, args...);
}
const int INF = 1e9 + 5;
const int N = 3e5 + 5;
const int M = 30;
const long long oo = LLONG_MAX;
const int mod = 998244353;
bool ask(int x, int y, int z) {
  cout << "? " << x + 1 << " " << y + 1 << " " << z + 1 << '\n';
  string ret;
  cin >> ret;
  return ret == "Yes";
}
int n, k;
vector<int> findPath(int x, int y) {
  vector<int> path;
  for (int z = 0; z < n; ++z) {
    if (z == x || z == y) continue;
    if (ask(x, z, y)) path.push_back(z);
  }
  return path;
}
int main() {
  cin >> n >> k;
  int deep = 0, sum = 1, cur = 1;
  for (; sum != n; ++deep) {
    cur *= k;
    sum += cur;
  }
  debug("deep", deep);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int x = i;
      int y = j;
      for (int z = 0; z < n; ++z) {
        if (z == x || z == y) continue;
        if (ask(z, x, y))
          x = z;
        else if (ask(x, y, z))
          y = z;
      }
      vector<int> path = findPath(x, y);
      if ((int)path.size() == 2 * deep - 1) {
        sort((path).begin(), (path).end(),
             [&](const int a, const int b) { return ask(x, a, b); });
        cout << "! " << path[deep - 1] + 1 << '\n';
        return 0;
      }
    }
  }
  return 0;
}
