#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
double fixAngle(double A) { return A > 1 ? 1 : (A < -1 ? -1 : A); }
double dcmp(double a, double b) {
  return fabs(a - b) < 1e-6 ? 0 : a > b ? 1 : -1;
}
struct trie {
  int child_cnt = 0;
  int is_root = 0;
  int is_end = 0;
  trie* child[26];
  trie(int state) {
    is_end = 0;
    is_root = state;
    child_cnt = 0;
    for (int i = 0; i < 26; i++) child[i] = NULL;
  }
  void insert_word(string s) {
    if (s.empty()) {
      is_end = 1;
      return;
    }
    if (child[s[s.size() - 1] - 'a'] == NULL) {
      child_cnt++;
      child[s[s.size() - 1] - 'a'] = new trie(0);
    }
    char c = s[s.size() - 1];
    s.pop_back();
    child[c - 'a']->insert_word(s);
  }
  int count_steps(string s) {
    if (s.empty()) return 0;
    char c = s[s.size() - 1];
    s.pop_back();
    return (int)(child_cnt != 1 || is_root || is_end) +
           child[c - 'a']->count_steps(s);
  }
};
set<int, int> vis;
int main() {
  vector<pair<long long, long long>> ans;
  long long x;
  cin >> x;
  long long n = 1;
  while (n <= 10000000) {
    if ((6 * x + ((n) * (n + 1) * (n - 1))) % ((n) * (n + 1) * (3)) != 0) {
    } else {
      ans.push_back(
          {n, (6 * x + ((n) * (n + 1) * (n - 1))) / ((n) * (n + 1) * (3))});
      if (ans[ans.size() - 1].first > ans[ans.size() - 1].second) {
        ans.pop_back();
        break;
      }
      if (ans[ans.size() - 1].first == ans[ans.size() - 1].second) break;
    }
    n++;
  }
  int t = ans.size();
  for (int i = 0; i < t; i++) {
    if (ans[i].first == ans[i].second) continue;
    ans.push_back({ans[i].second, ans[i].first});
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (auto pp : ans) {
    cout << pp.first << " " << pp.second << endl;
  }
}
