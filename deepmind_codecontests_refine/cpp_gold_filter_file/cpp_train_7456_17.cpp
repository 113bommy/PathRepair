#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void chkmax(T &x, const T &y) {
  if (x < y) x = y;
}
template <class T>
inline void chkmin(T &x, const T &y) {
  if (x > y) x = y;
}
const int MAXN = (1 << 20);
int n;
string s;
vector<int> a, b;
void read() {
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'P')
      a.push_back(i);
    else if (s[i] == '*')
      b.push_back(i);
  }
}
pair<int, int> inter[MAXN], ini[MAXN];
bool bck[MAXN], cov[MAXN];
bool check(int t) {
  for (int ii = 0; ii < (int)a.size(); ii++) bck[ii] = 0, inter[ii] = {-1, -1};
  int curr_pos = 0, i = 0;
  for (int x : a) {
    if (curr_pos == (int)b.size()) return true;
    if (x >= b[curr_pos]) {
      if (x - b[curr_pos] > t) return false;
      bck[i] = 1;
      while (curr_pos < (int)b.size() && x >= b[curr_pos]) {
        if (inter[i].first == -1) inter[i].first = curr_pos;
        inter[i].second = curr_pos;
        curr_pos++;
      }
      if (i && bck[i - 1] && cov[i - 1] && x - b[ini[i - 1].first] <= t) {
        bck[i - 1] ^= 1;
        bck[i - 2] ^= 1;
        cov[i] = 1;
        ini[i] = inter[i];
        inter[i].first = ini[i - 1].first;
        while (curr_pos < (int)b.size() && (b[curr_pos] - a[i - 1]) <= t)
          curr_pos++;
      } else if (i && bck[i - 1] && x - b[inter[i - 1].first] <= t) {
        bck[i - 1] ^= 1;
        cov[i] = 1;
        ini[i] = inter[i];
        inter[i].first = inter[i - 1].first;
        while (curr_pos < (int)b.size() && (b[curr_pos] - a[i - 1]) <= t)
          curr_pos++;
      }
    } else
      while (curr_pos < (int)b.size() && (b[curr_pos] - x) <= t) curr_pos++;
    i++;
  }
  if (curr_pos == (int)b.size()) return true;
  return false;
}
void solve() {
  if (a.size() == 1) {
    int pos = a[0];
    int ans_v = 0, ans_t = 0;
    for (int i = 0; i < pos; i++)
      if (s[i] == '*') {
        if (ans_t == 0) ans_t = pos - i;
        ans_v++;
      }
    pair<int, int> ret = {ans_v, ans_t};
    ans_v = 0;
    ans_t = 0;
    for (int i = pos + 1; i < n; i++)
      if (s[i] == '*') {
        ans_t = i - pos;
        ans_v++;
      }
    if (ans_v < ret.first) ans_v = ret.first, ans_t = ret.second;
    if (ans_v == ret.first) ans_t = min(ans_t, ret.second);
    cout << ans_v << " " << ans_t << '\n';
    return;
  }
  int low = 0, high = 3 * n, mid, ret = (int)1e9;
  while (low <= high) {
    mid = (low + high) >> 1;
    if (check(mid))
      ret = mid, high = mid - 1;
    else
      low = mid + 1;
  }
  cout << b.size() << " " << ret << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  read();
  solve();
  return 0;
}
