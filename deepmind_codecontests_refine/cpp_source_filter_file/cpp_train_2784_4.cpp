#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void amin(T &a, U b) {
  a = (a > b ? b : a);
}
template <typename T, typename U>
inline void amax(T &a, U b) {
  a = (a > b ? a : b);
}
int64_t ans;
map<vector<int>, int64_t> mp;
void solve(int digs, vector<int> &cnt, vector<int> &freq) {
  if (mp[cnt]) return;
  int tot = 0, here = 1;
  for (int i = 1; i <= 9; ++i) tot += cnt[i];
  here *= tot;
  tot--;
  tot += cnt[0];
  for (int i = 1; i < digs; ++i) here *= tot--;
  for (int i = 0; i <= 9; ++i) {
    if (cnt[i]) {
      for (int j = 1; j <= cnt[i]; ++j) here /= j;
    }
  }
  mp[cnt] = here;
  ans += here;
  for (int i = 0; i <= 9; ++i) {
    if (cnt[i] < freq[i]) {
      ++cnt[i];
      solve(digs + 1, cnt, freq);
      --cnt[i];
    }
  }
}
void solve() {
  string s;
  cin >> s;
  int minDig = 0;
  vector<int> freq(10, 0);
  vector<int> temp(10, 0);
  for (char c : s) freq[c - '0']++;
  for (int i = 0; i <= 9; ++i)
    if (freq[i]) ++minDig, ++temp[i];
  solve(minDig, temp, freq);
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tests = 1;
  while (tests--) {
    solve();
  }
}
