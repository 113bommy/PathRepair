#include <bits/stdc++.h>
using namespace std;
int k, n;
vector<string> s(0);
vector<bool> can(0);
void kek() {
  for (int i = 0; i < k; i++) {
    set<char> st;
    for (auto ch : s[i]) st.insert(ch);
    if (st.size() < n) can[i] = true;
  }
}
bool check(string t) {
  for (int i = 0; i < k; i++) {
    vector<int> diff(0);
    for (int j = 0; j < n; j++) {
      if (s[i][j] != t[j]) diff.push_back(j);
    }
    if (diff.size() == 0 && can[i]) continue;
    if (diff.size() == 2 && t[diff[0]] == s[i][diff[1]] &&
        t[diff[1]] == s[i][diff[0]])
      continue;
    return false;
  }
  cout << t;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> k >> n;
  can.resize(k, false);
  s.resize(k);
  for (int i = 0; i < k; i++) cin >> s[i];
  kek();
  if (k == 1) {
    if (n == 1) {
      cout << -1;
    } else {
      string t = s[0];
      swap(t[0], t[1]);
      cout << t;
    }
    return 0;
  }
  for (int i = 1; i < k; i++) {
    vector<int> pos(0);
    for (int j = 0; j < n; j++)
      if (s[0][j] != s[i][j]) pos.push_back(j);
    if (pos.size() > 4) {
      cout << -1;
      return 0;
    }
    if (pos.size() == 0) {
      string t = s[0];
      swap(t[0], t[1]);
      if (check(t)) return 0;
    }
    for (auto p : pos) {
      for (int q = 0; q < n; q++) {
        if (p == q) continue;
        string t = s[0];
        swap(t[p], t[q]);
        if (check(t)) return 0;
      }
    }
  }
  cout << -1;
  return 0;
}
