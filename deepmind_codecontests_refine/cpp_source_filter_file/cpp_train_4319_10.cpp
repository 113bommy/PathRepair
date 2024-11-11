#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000009;
map<int, std::pair<int, int> > all;
map<std::pair<int, int>, int> all1;
set<int> allowed;
bool isSafe(int idx) {
  assert(all.find(idx) != all.end());
  std::pair<int, int> cord = all[idx];
  int x = cord.first, y = cord.second;
  if (y == 0) return true;
  bool f = 0;
  auto it = all1.find({x - 1, y - 1});
  if (it != all1.end()) f |= true;
  it = all1.find({x, y - 1});
  if (it != all1.end()) f |= true;
  it = all1.find({x + 1, y - 1});
  if (it != all1.end()) f |= true;
  return f;
}
bool is_allowed(int idx) {
  assert(all.find(idx) != all.end());
  std::pair<int, int> cord = all[idx];
  int x = cord.first, y = cord.second;
  all.erase(idx);
  all1.erase(cord);
  auto it = all1.find({x - 1, y + 1});
  bool f = true;
  if (it != all1.end()) f &= isSafe(it->second);
  it = all1.find({x, y + 1});
  if (it != all1.end()) f &= isSafe(it->second);
  it = all1.find({x + 1, y + 1});
  if (it != all1.end()) f &= isSafe(it->second);
  all[idx] = cord;
  all1[cord] = idx;
  return f;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    all.insert({i, {x, y}});
    all1.insert({{x, y}, i});
  }
  for (int i = 0; i < (n); ++i) {
    if (is_allowed(i)) allowed.insert(i);
  }
  vector<int> answers;
  auto it = allowed.begin();
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      it = --allowed.end();
    } else
      it = allowed.begin();
    answers.push_back(*it);
    std::pair<int, int> cord = all[*it];
    int x = cord.first, y = cord.second;
    all.erase(*it);
    all1.erase(cord);
    allowed.erase(it);
    for (int j = -1; j < 2; ++j) {
      int xx = x + j, yy = y + 1;
      auto it1 = all1.find({xx, yy});
      if (it1 != all1.end()) {
        int inv = it1->second;
        if (!is_allowed(inv)) allowed.erase(inv);
      }
    }
    for (int j = -1; j < 2; ++j) {
      int xx = x + j, yy = y - 1;
      auto it1 = all1.find({xx, yy});
      if (it1 != all1.end()) {
        int inv = it1->second;
        if (is_allowed(inv)) allowed.insert(inv);
      }
    }
  }
  assert(answers.size() == n);
  reverse(answers.begin(), answers.end());
  long long ans = 0;
  long long mul = 1;
  for (int i = 0; i < n; ++i) {
    ans = ans + (long long)answers[i] * mul % MOD;
    ans %= MOD;
    mul = mul * (long long)n % MOD;
    cerr << answers[i] << " ";
  }
  cout << ans << endl;
  return 0;
}
