#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> AI;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    AI.push_back({a, i});
  }
  sort(AI.begin(), AI.end());
  const int INF = 1e9;
  int ans[100001];
  fill(ans, ans + N + 1, INF);
  map<int, int> segments;
  int num[100001];
  fill(num, num + N + 1, 0);
  set<int> exist;
  for (auto& p : AI) {
    int a = p.first, i = p.second;
    int lb = i, ub = i + 1;
    auto aft = segments.upper_bound(i);
    bool del_aft = false;
    if (aft != segments.end() && aft->first == ub) {
      ub = aft->second;
      int sz = aft->second - aft->first;
      num[sz]--;
      if (num[sz] == 0) exist.erase(sz);
      del_aft = true;
    }
    if (aft != segments.begin() && prev(aft)->second == lb) {
      auto bef = prev(aft);
      lb = bef->first;
      int sz = bef->second - bef->first;
      num[sz]--;
      if (num[sz] == 0) exist.erase(sz);
      segments.erase(bef);
    }
    if (del_aft) segments.erase(aft);
    int sz = ub - lb;
    num[sz]++;
    exist.insert(sz);
    segments[lb] = ub;
    if (exist.size() == 1) {
      ans[num[sz]] = min(ans[num[sz]], a + 1);
    }
  }
  for (int n = N; n >= 0; n--) {
    if (ans[n] < INF) {
      cout << ans[n] << endl;
      return 0;
    }
  }
  return 0;
}
