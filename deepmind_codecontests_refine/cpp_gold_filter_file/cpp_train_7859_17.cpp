#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int OFF = (1 << 15);
int n, k, q;
pair<pair<int, int>, pair<int, int> > p[15002];
int wh[30002];
int q1[30002];
int q2[30002];
long long pot[1002];
vector<int> v[2 * OFF + 5];
long long dp[OFF + 5][1002];
long long tdp[1002];
void update(int a, int b, int l, int r, int x, int kol) {
  if (r <= a || b <= l) return;
  if (a <= l && r <= b) {
    v[x].push_back(kol);
    return;
  }
  update(a, b, l, (l + r) / 2, x * 2, kol);
  update(a, b, (l + r) / 2, r, x * 2 + 1, kol);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  pot[0] = 1;
  for (int i = 1; i <= k; i++) {
    pot[i] = pot[i - 1] * (1e7 + 19);
    pot[i] %= MOD;
  }
  for (int i = 0; i < n; i++) {
    cin >> p[i].first.first >> p[i].first.second;
    p[i].second.first = 0;
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> wh[i];
    if (wh[i] == 1) {
      cin >> q1[i] >> q2[i];
      p[n] = {{q1[i], q2[i]}, {i, 0}};
      n++;
    } else if (wh[i] == 2) {
      cin >> q1[i];
      q1[i]--;
      p[q1[i]].second.second = i;
    }
  }
  for (int i = 0; i < n; i++) {
    if (p[i].second.second == 0) p[i].second.second = q + 1;
    update(p[i].second.first, p[i].second.second + 1, 0, OFF, 1, i);
  }
  for (int i = 1; i < OFF; i++) {
    for (int l = 0; l < v[i].size(); l++) {
      for (int j = k; j >= 0; j--) {
        int t = v[i][l];
        if (j - p[t].first.second >= 0) {
          dp[i][j] =
              max(dp[i][j], dp[i][j - p[t].first.second] + p[t].first.first);
        }
        if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
      }
    }
    for (int j = 0; j <= k; j++) {
      if (i * 2 < OFF) dp[i * 2][j] = dp[i][j];
      if (i * 2 + 1 < OFF) dp[i * 2 + 1][j] = dp[i][j];
    }
  }
  for (int i = 1; i <= q; i++) {
    if (wh[i] == 3) {
      long long sol = 0;
      int c = OFF + i;
      c /= 2;
      for (int j = 1; j <= k; j++) tdp[j] = dp[c][j];
      for (int l = 0; l < v[OFF + i].size(); l++) {
        int t = v[OFF + i][l];
        for (int j = 1; j <= k; j++) {
          if (j - p[t].first.second >= 0) {
            tdp[j] = max(tdp[j], tdp[j - p[t].first.second] + p[t].first.first);
          }
          if (j > 0) tdp[j] = max(tdp[j], tdp[j - 1]);
        }
      }
      for (int j = 1; j <= k; j++) {
        sol += (tdp[j] % MOD * pot[j - 1]) % MOD;
        sol %= MOD;
      }
      cout << sol << endl;
    }
  }
  return 0;
}
