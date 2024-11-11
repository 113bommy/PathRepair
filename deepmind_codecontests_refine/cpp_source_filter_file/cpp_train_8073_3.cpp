#include <bits/stdc++.h>
using namespace std;
int n, L, p, t;
int dp[100001], pos[100001];
vector<pair<int, int> > S;
void change(int id, int new_val, int new_pos) {
  if (new_pos + (dp[id] - new_val) * p < pos[id]) {
    pos[id] = new_pos;
    dp[id] = new_val;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> L >> n >> p >> t;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    if (r - l >= p) S.push_back({l, r});
  }
  S.push_back({2000000010, 2000000010});
  int i = -1;
  for (auto it : S) {
    ++i;
    pos[i] = it.first;
  }
  for (i = 0; i < S.size(); i++) {
    if (S[i].first == 2000000010) break;
    change(i + 1, dp[i], pos[i + 1]);
    int new_val = dp[i] + ((S[i].second - pos[i]) / p);
    int new_pos = pos[i] + ((S[i].second - pos[i]) / p) * p + t;
    int low = i, high = S.size(), cur;
    while (high - low > 1) {
      cur = (high + low) / 2;
      if (new_pos >= S[cur].first) {
        low = cur;
      } else {
        high = cur;
      }
    }
    cur = low;
    if (new_pos >= S[cur].first && new_pos <= S[cur].second) {
      change(cur, new_val, new_pos);
    }
    change(cur + 1, new_val, S[cur + 1].first);
  }
  cout << dp[S.size() - 1];
  return 0;
}
