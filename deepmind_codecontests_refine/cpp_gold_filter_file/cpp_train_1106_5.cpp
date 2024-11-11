#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr int N = 1.5e7 + 5;
int n, k;
vector<string> vec;
bool isShit = 0;
bool check(string& s1, string& s2) {
  int i1 = -1, i2 = -1;
  for (int i = 0; i < n; i++)
    if (s1[i] != s2[i]) {
      if (i1 == -1)
        i1 = i;
      else if (i2 == -1)
        i2 = i;
      else
        return false;
    }
  if (i1 != -1 && i2 == -1) return false;
  if (i1 == -1 && i2 == -1) {
    return isShit;
  }
  return s1[i1] == s2[i2] && s1[i2] == s2[i1];
}
void Solve() {
  cin >> k >> n;
  vec.resize(k);
  for (int i = 0; i < k; i++) cin >> vec[i];
  auto s1 = vec[0];
  if (k == 1) {
    swap(s1[0], s1[1]);
    cout << s1;
    return;
  }
  vector<int> pos;
  vector<char> val;
  string good = s1;
  int cnt[26];
  fill(cnt, cnt + 26, 0);
  for (auto c : good) {
    cnt[c - 'a']++;
    if (cnt[c - 'a'] > 1) isShit = 1;
  }
  vector<bool> have(n);
  for (int i = 1; i < k && val.size() < 7; i++) {
    for (int j = 0; j < n; j++) {
      if (s1[j] != vec[i][j] && !have[j]) {
        have[j] = 1;
        val.push_back(s1[j]);
        if (val.size() == 7) break;
      }
    }
  }
  if (val.size() == 0) {
    val = {good[0], good[1]};
    pos = {0, 1};
  } else {
    for (int i = 0; i < n; i++)
      if (have[i]) pos.push_back(i);
  }
  sort(val.begin(), val.end());
  do {
    for (int i = 0; i < val.size(); i++) good[pos[i]] = val[i];
    bool yes = 1;
    for (auto& s : vec) {
      if (!check(s, good)) {
        yes = 0;
        break;
      }
    }
    if (yes) {
      cout << good;
      return;
    }
  } while (next_permutation(val.begin(), val.end()));
  cout << -1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  Solve();
  return 0;
}
