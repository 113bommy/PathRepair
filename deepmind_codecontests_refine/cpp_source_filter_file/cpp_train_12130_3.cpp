#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
map<int, int> p;
int dp[1000000 + 10];
int rec(int dist) {
  if (dist < 0) return 0;
  int val = p[dist];
  int sec = dist - val - 1;
  if (sec < 0) return 1;
  int &st = dp[dist];
  if (st != -1) return st;
  int low = 0, high = v.size() - 1, mid;
  while (low < high) {
    mid = low + (high - low) / 2;
    if (v[mid].first > sec)
      high = mid;
    else if (v[mid].first < sec)
      low = mid + 1;
    else {
      high = mid;
      break;
    }
  }
  if (v[high].first > sec) {
    if (high == 0) return 0;
    if (v[high - 1].first > sec) return 0;
    high--;
  }
  int e = 1 + rec(v[high].first);
  return st = e;
}
int main() {
  int n, m, k, d, t, tem1, tem2, tem3, tem4, y = 1, sum = 0, ans = 0,
                                             mini = 1e9;
  string s, c;
  memset(dp, -1, sizeof dp);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &tem1, &tem2);
    v.push_back({tem1, tem2});
    p[tem1] = tem2;
  }
  sort(v.begin(), v.end());
  for (int i = v.size() - 1; i >= 0; i--) {
    int e = v[i].first;
    mini = min(n - rec(e), mini);
  }
  printf("%d", mini);
  return 0;
}
