#include <bits/stdc++.h>
using namespace std;
int col[200001];
deque<int> ans;
void dfs(int v, vector<vector<int>>& all) {
  for (auto e : all[v]) {
    if (col[e] > 0) {
      if ((col[e] % 2 == 1 && col[e] >= 3) || (col[v] % 2 == 1 && col[v] > 1))
        continue;
      col[e] = 3;
      ans.push_back(e);
    }
  }
  for (auto e : all[v]) {
    if (col[e] == 0) {
      ans.push_back(e);
      col[e] = col[v] + 1;
    }
  }
  return;
}
void solve() {
  int n;
  cin >> n;
  vector<int> cnt(22);
  vector<long long> all(n);
  for (int i = 0; i < n; i++) cin >> all[i];
  for (int i = 0; i < n; i++) {
    int j = 0;
    for (int y = 0; y < 22; y++) {
      if (all[i] % 2 == 1) cnt[y]++;
      all[i] /= 2;
    }
  }
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int y = 0; y < 22; y++) {
      if (cnt[y] >= i + 1) sum += pow(2, y);
    }
    all[i] = sum;
  }
  long long ans = 0;
  for (auto c : all) ans += c * c;
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int t;
  t = 1;
  while (t > 0) {
    t--;
    solve();
  }
}
