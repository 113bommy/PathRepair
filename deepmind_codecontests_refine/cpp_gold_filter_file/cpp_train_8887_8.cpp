#include <bits/stdc++.h>
#pragma comment(linker, "/stack:16000000")
using namespace std;
template <typename first>
inline first abs(const first& a) {
  return a < 0 ? -a : a;
}
template <typename first>
inline first sqr(const first& a) {
  return a * a;
}
const int INF = int(1e9);
const int NMAX = int(1e4);
const long double EPS = 1e-9;
const long double PI = 3.1415926535897932384626433832795;
const int N = 500 + 13;
int n, m;
pair<int, int> p[N];
int seg[N];
vector<int> ans;
bool used[N];
bool go(int fir) {
  ans.clear();
  vector<int> lens;
  for (int i = fir; i < n; i += 2) {
    int cur = 0;
    int prev = (i - 1 + n) % n;
    if (p[i].first != p[prev].first && p[i].second != p[prev].second)
      return false;
    cur += abs(p[i].first - p[prev].first) + abs(p[i].second - p[prev].second);
    int next = (i + 1) % n;
    if (p[i].first != p[next].first && p[i].second != p[next].second)
      return false;
    cur += abs(p[i].first - p[next].first) + abs(p[i].second - p[next].second);
    lens.push_back(cur);
  }
  memset(used, 0, sizeof(used));
  int it = 0;
  for (int i = 0; i < int(n); i++) {
    if ((i & 1) == fir) {
      bool ok = false;
      for (int j = 0; j < int(m); j++)
        if (!used[j] && seg[j] == lens[it]) {
          ok = true;
          ans.push_back(j);
          used[j] = true;
          it++;
          break;
        }
      if (!ok) return false;
    } else
      ans.push_back(-2);
  }
  return true;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < int(n); i++) scanf("%d%d", &p[i].first, &p[i].second);
  for (int i = 0; i < int(m); i++) scanf("%d", &seg[i]);
  if (go(0)) {
    cout << "YES" << endl;
    for (int i = 0; i < int(int((ans).size())); i++) printf("%d ", ans[i] + 1);
    return 0;
  }
  if (go(1)) {
    cout << "YES" << endl;
    for (int i = 0; i < int(int((ans).size())); i++) printf("%d ", ans[i] + 1);
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}
