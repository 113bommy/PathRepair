#include <bits/stdc++.h>
using namespace std;
int n, c, d;
int bea[100005];
int cost[100005];
char type[100005];
int solve(vector<pair<int, int> > vec, int money) {
  if (vec.size() <= 1) return 0;
  sort(vec.begin(), vec.end());
  int ans = 0;
  int best = 0;
  int index = 1;
  vector<int> vec2;
  for (int i = 0; i < vec.size(); i++) vec2.push_back(vec[i].second);
  for (int i = 1; i < vec2.size(); i++) vec2[i] = max(vec2[i - 1], vec2[i]);
  for (int i = 1; i < vec.size(); i++)
    if (vec[i - 1].first + vec[i].first <= money)
      ans = max(ans, vec2[i - 1] + vec[i].second);
  for (int i = vec.size() - 1; i >= 0; i--) {
    while (index < i && vec[index].first + vec[i].first <= money) {
      index++;
    }
    if (index > i) break;
    if (vec[index - 1].first + vec[i].first <= money)
      ans = max(ans, vec2[index - 1] + vec[i].second);
  }
  return ans;
}
int main() {
  cin >> n >> c >> d;
  for (int i = 0; i < n; i++) {
    cin >> bea[i];
    cin >> cost[i];
    cin >> type[i];
  }
  int bestD = 0;
  int bestC = 0;
  for (int i = 0; i < n; i++) {
    if (type[i] == 'C') {
      if (cost[i] <= c) bestC = max(bestC, bea[i]);
    } else {
      if (cost[i] <= d) bestD = max(bestD, bea[i]);
    }
  }
  int ans = 0;
  if (bestD != 0 && bestC != 0) ans = bestD + bestC;
  vector<pair<int, int> > vec;
  for (int i = 0; i < n; i++)
    if (type[i] == 'C') vec.push_back({cost[i], bea[i]});
  ans = max(ans, solve(vec, c));
  vec.clear();
  for (int i = 0; i < n; i++)
    if (type[i] == 'D') vec.push_back({cost[i], bea[i]});
  ans = max(ans, solve(vec, d));
  cout << ans << endl;
}
