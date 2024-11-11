#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 113;
vector<int> go[N][2];
bool exist[N][2], bad[N];
void print(vector<int> kek) {
  cout << "YES" << '\n';
  int sz = kek.size();
  vector<bool> used(sz);
  for (int i = 0; i < sz; i++) {
    if (kek[i] != -1) used[kek[i]] = 1;
  }
  int c = 0;
  for (int i = 0; i < sz; i++) {
    if (kek[i] == -1) {
      while (used[c]) c++;
      cout << (char)(c + 'a');
      used[c] = 1;
    } else
      cout << (char)(kek[i] + 'a');
  }
  cout << '\n';
}
void solve() {
  int sz;
  cin >> sz;
  string ss, aa, bb;
  cin >> ss >> aa >> bb;
  vector<int> s, a, b;
  for (auto i : ss) s.push_back(i - 'a');
  for (auto i : aa) a.push_back(i - 'a');
  for (auto i : bb) b.push_back(i - 'a');
  int n = s.size();
  for (int i = 0; i <= n; i++) {
    bad[i] = 0;
    for (int j = 0; j < 2; j++) go[i][j].resize(sz, -1), exist[i][j] = 0;
  }
  bad[0] = 1;
  for (int i = 0; i < n; i++) {
    bad[i + 1] = bad[i];
    if (b[i] != a[i]) bad[i + 1] = 0;
  }
  exist[0][0] = 1, exist[0][1] = 1;
  for (int i = 0; i <= n; i++) {
    if (exist[i][0]) {
      if (i == n) {
        print(go[i][0]);
        return;
      }
      auto lol = go[i][0];
      vector<bool> used(sz);
      for (int j = 0; j < sz; j++) {
        if (lol[j] != -1) used[lol[j]] = 1;
      }
      if (lol[s[i]] == a[i] || (!used[a[i]] && lol[s[i]] == -1)) {
        go[i + 1][0] = lol;
        go[i + 1][0][s[i]] = a[i];
        exist[i + 1][0] = 1;
      }
      int st = a[i] + 1, en = sz - 1;
      if (bad[i]) en = b[i] - 1;
      for (; st <= en; st++) {
        if (lol[s[i]] == st || (!used[st] && lol[s[i]] == -1)) {
          lol[s[i]] = st;
          print(lol);
          return;
        }
      }
    }
    if (exist[i][1]) {
      if (i == n) {
        print(go[i][1]);
        return;
      }
      auto lol = go[i][1];
      vector<bool> used(sz);
      for (int j = 0; j < sz; j++) {
        if (lol[j] != -1) used[lol[j]] = 1;
      }
      if (lol[s[i]] == b[i] || (!used[b[i]] && lol[s[i]] == -1)) {
        go[i + 1][1] = lol;
        go[i + 1][1][s[i]] = b[i];
        exist[i + 1][1] = 1;
      }
      int st = 1, en = b[i] - 1;
      if (bad[i]) st = a[i] + 1;
      for (; st <= en; st++) {
        if (lol[s[i]] == st || (!used[st] && lol[s[i]] == -1)) {
          lol[s[i]] = st;
          print(lol);
          return;
        }
      }
    }
  }
  cout << "NO" << '\n';
}
signed main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
