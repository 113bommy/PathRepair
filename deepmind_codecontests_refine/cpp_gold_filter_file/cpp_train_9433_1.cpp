#include <bits/stdc++.h>
using namespace std;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
string s[1000005];
vector<int> hs[1000005];
int n;
vector<int> save[1000005];
int mx = 0;
long long pw[1000005];
int get(int idx, int len) {
  long long now = hs[idx][len - 1];
  now -= (s[idx][0] - 'a' + 1) * pw[len - 1];
  now %= 1000000009;
  now = (now + 1000000009) % 1000000009;
  return now;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  pw[0] = 1;
  for (int i = 1; i < 1000005; i++) pw[i] = pw[i - 1] * 137 % 1000000009;
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      long long now = 0;
      int j = 0;
      for (auto u : s[i]) {
        now = (now * 137 + (u - 'a' + 1)) % 1000000009;
        hs[i].push_back(now);
      }
      save[s[i].size()].push_back(i);
      mx = max(mx, (int)s[i].size());
    }
    vector<int> cur;
    unordered_map<int, bool, custom_hash> dead[2];
    int c = 0;
    int ans = 0;
    for (int len = mx; len >= 1; len--) {
      for (int idx : save[len]) cur.push_back(idx);
      for (int idx : cur) {
        int now = hs[idx][len - 1];
        if (dead[c].count(now) == 0) {
          ans++;
          if (len > 1) {
            dead[c ^ 1][get(idx, len)] = 1;
          }
          dead[c][now] = 1;
        }
      }
      dead[c].clear();
      c ^= 1;
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
      hs[i].clear();
      save[s[i].size()].clear();
    }
    mx = 0;
  }
}
