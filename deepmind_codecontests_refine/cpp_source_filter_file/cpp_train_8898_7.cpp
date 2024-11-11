#include <bits/stdc++.h>
using namespace std;
const int inf = 1000 * 1000 * 1000;
struct st {
  int ar[4];
  st() {
    memset(ar, 0, sizeof(ar));
    ;
  }
  void Set(int pos) { ar[pos / 32] |= 1 << (pos % 32); }
  void Erase(int pos) {
    ar[pos / 32] &= ((-1) ^ (1 << (pos % 32)));
    ;
  }
  bool Get(int pos) {
    if (ar[pos / 32] & (1 << (pos % 32))) return 1;
    return 0;
  }
  bool Empty() {
    return (ar[0] == 0 && ar[1] == 0 && ar[2] == 0 && ar[3] == 0);
  }
};
int n, k;
string s, res, pt;
int DP(int pos, st to) {
  if (pos == n && to.Empty()) {
    cout << res << endl;
    exit(0);
  }
  if (pos == n) return 0;
  char ar[26];
  for (int i = 0; i < k; i++) ar[i] = 1;
  if (pos < pt.size() && pt[pos] == '0') to.Set(pos);
  if (res[pos] != 0) {
    st t = to;
    for (int j = 0; j < n; j++) {
      if (!to.Get(j)) continue;
      if (s[pos - j] != res[pos])
        t.Erase(j);
      else if (pos - j + 1 == k)
        return 0;
    }
    if (DP(pos + 1, t)) return 1;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (!to.Get(i)) continue;
    ar[s[pos - i] - 'a'] = 0;
  }
  for (int i = 0; i < k; i++)
    if (ar[i] == 1) {
      res[pos] = i + 'a';
      st t;
      return DP(pos, t);
    }
  for (int i = 0; i < k; i++) {
    st t = to;
    bool ok = 1;
    for (int j = 0; j < n; j++) {
      if (!to.Get(j)) continue;
      if (s[pos - j] != 'a' + i)
        t.Erase(j);
      else if (pos - j + 1 == k) {
        ok = 0;
        break;
      }
    }
    if (!ok) continue;
    res[pos] = i + 'a';
    if (DP(pos + 1, t)) return 1;
  }
  return 0;
}
int main() {
  cin >> n >> k >> s >> pt;
  for (int i = 0; i < n; i++) res += (char)0;
  for (int i = 0; i < pt.size(); i++) {
    if (pt[i] == '1') {
      for (int j = 0; j < s.size(); j++) res[i + j] = s[j];
    }
  }
  bool ok = 1;
  for (int i = 0; i < pt.size(); i++) {
    if (pt[i] == '1') {
      for (int j = 0; j < s.size(); j++)
        if (res[i + j] != s[j]) ok = 0;
    }
  }
  if (!ok) {
    cout << "No solution" << endl;
    return 0;
  }
  st t;
  if (!DP(0, t)) cout << "No solution" << endl;
  return 0;
}
