#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int cnt[10], t1[10], t2[10];
string s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  for (int i = 0; i < s.size(); i++) cnt[s[i] - '0']++;
  int ans = -1e8, anst = -1, t, now;
  for (int i = 1; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) t1[j] = t2[j] = cnt[j];
    if (!t1[i] || !t2[10 - i]) continue;
    t1[i]--;
    t2[10 - i]--;
    t = 0;
    for (int j = 0; j <= 9; j++) {
      now = min(t1[j], t2[9 - j]);
      t += now;
      t1[j] -= now;
      t2[j] -= now;
    }
    t += min(t1[0], t2[0]);
    if (ans < t) {
      ans = t;
      anst = i;
    }
  }
  deque<int> ans1, ans2;
  if (anst == -1) {
    for (int i = 0; i <= 9; i++) {
      for (int j = 1; j <= cnt[i]; j++) {
        ans1.emplace_back(i);
        ans2.emplace_back(i);
      }
    }
  } else {
    ans1.emplace_back(anst);
    ans2.emplace_back(10 - anst);
    for (int i = 0; i <= 9; i++) t1[i] = t2[i] = cnt[i];
    t1[anst]--;
    t2[10 - anst]--;
    for (int i = 0; i <= 9; i++) {
      t = min(t1[i], t2[9 - i]);
      for (int j = 1; j <= t; j++) {
        ans1.emplace_back(i);
        ans2.emplace_back(9 - i);
      }
      t1[i] -= t;
      t2[9 - i] -= t;
    }
    t = min(t1[0], t2[0]);
    for (int i = 1; i <= t; i++) {
      ans1.emplace_front(0);
      ans2.emplace_front(0);
    }
    t1[0] -= t;
    t2[0] -= t;
    for (int i = 0; i <= 9; i++) {
      for (int j = 1; j <= t1[i]; j++) ans1.emplace_back(i);
      for (int j = 1; j <= t2[i]; j++) ans2.emplace_back(i);
    }
  }
  reverse(ans1.begin(), ans1.end());
  reverse(ans2.begin(), ans2.end());
  for (auto u : ans1) cout << u;
  cout << '\n';
  for (auto u : ans2) cout << u;
  return 0;
}
