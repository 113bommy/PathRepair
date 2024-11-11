#include <bits/stdc++.h>
using namespace std;
int dp[512][1024];
int in[512], out[512], w[512], s[512], V[512];
int n, S;
vector<int> inside[512];
int gao(int k, int S) {
  if (S <= 0) return 0;
  if (dp[k][S] != -1) {
    return dp[k][S];
  }
  int res = 0;
  int start = in[k];
  int finish = out[k];
  vector<int> v(finish + 1, 0);
  int offset = 0, sz = inside[k].size();
  for (int i = start; i <= finish; i++) {
    if (i != start) {
      v[i] = v[i - 1];
    }
    while (offset < sz && i == out[inside[k][offset]]) {
      int& nxt = inside[k][offset];
      v[i] = max(v[i], v[in[nxt]] + gao(nxt, min(s[k], S - w[k])));
      offset++;
    }
  }
  res = v[finish] + V[k];
  return dp[k][S] = res;
}
int main() {
  cin >> n >> S;
  for (int i = 0; i < (n); i++) {
    cin >> in[i] >> out[i] >> w[i] >> s[i] >> V[i];
  }
  in[n] = 0;
  out[n] = 2 * n + 1;
  w[n] = 0;
  s[n] = S;
  V[n] = 0;
  n++;
  memset(dp, -1, sizeof dp);
  vector<pair<int, int> > v;
  for (int i = 0; i < (n); i++) {
    v.push_back(make_pair(out[i], i));
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < (n); i++) {
    for (int j = 0; j < (v.size()); j++) {
      int id = v[j].second;
      if (in[i] <= in[id] && out[id] <= out[i]) {
        if (i == id) continue;
        inside[i].push_back(id);
      }
    }
  }
  cout << gao(n - 1, S) << endl;
  return 0;
}
