#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> MAP;
int value[100005], cnt[26];
int SET(int mask, int pos) { return mask = (mask | (1 << pos)); }
bool CHECK(int mask, int pos) { return (bool)(mask & (1 << pos)); }
int RESET(int mask, int pos) { return mask = mask & ~(1 << pos); }
int calcHash(string &s) {
  int sz = s.size();
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < sz; i++) {
    cnt[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) cnt[i] = cnt[i] % 2;
  int hash_val = 0;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] == 1) {
      hash_val = hash_val | (1 << i);
    }
  }
  return hash_val;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    value[i] = calcHash(s);
    MAP[value[i]]++;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += MAP[value[i]] - 1;
    int tmp;
    for (int j = 0; j < 26; j++) {
      if (!CHECK(value[i], j)) {
        tmp = SET(value[i], j);
        ans += MAP[tmp];
      }
    }
    if (__builtin_popcount(value[i]) == 1) {
      ans += MAP[0];
    } else {
      for (int j = 0; j < 26; j++) {
        if (CHECK(value[i], j)) {
          tmp = RESET(value[i], j);
          ans += MAP[tmp];
        }
      }
    }
    MAP[value[i]]--;
  }
  cout << ans << "\n";
  return 0;
}
