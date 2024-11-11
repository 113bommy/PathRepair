#include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 1000 + 20;
int n, a[N], b[N], down[N * 3], up[N * 3];
bool mark[N];
vector<int> vec;
void compress() {
  for (int i = 0; i < n; i++) {
    vec.push_back(a[i]);
    vec.push_back(b[i]);
  }
  sort(vec.begin(), vec.end());
  vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin() + n;
    b[i] = lower_bound(vec.begin(), vec.end(), b[i]) - vec.begin() + n;
  }
}
bool dfs(int v, int len) {
  mark[v] = true;
  for (auto u : {a[v], b[v]}) {
    if (u < len + n) {
      if (up[u] == -1 || (mark[up[u]] == false && dfs(up[u], len))) {
        down[v] = u;
        up[u] = v;
        return true;
      }
    }
  }
  return false;
}
int max_matching(int len) {
  int res = 0;
  memset(up, -1, sizeof up);
  memset(down, -1, sizeof down);
  bool done = false;
  while (!done) {
    done = true;
    memset(mark, false, sizeof mark);
    for (int v = 0; v < n; v++)
      if (down[v] == -1 && mark[v] == false && dfs(v, len)) {
        done = false;
        res++;
      }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  compress();
  int st = n, en = vec.size(), ans = -1;
  while (st <= en) {
    int mid = st + en >> 1;
    if (max_matching(mid) == n) {
      ans = vec[mid - 1];
      en = mid - 1;
    } else
      st = mid + 1;
  }
  return cout << ans << endl, 0;
}
