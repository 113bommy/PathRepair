#include <bits/stdc++.h>
using namespace std;
int A[305], L[305];
int dp[305][305];
int up[305][305], down[305][305];
int DP[305];
bool ok[305][305];
vector<int> vx;
bool good(pair<int, int> p, pair<int, int> q) {
  if (p.first > q.first) swap(p, q);
  return q.first < p.second;
}
void ins(pair<int, int> p) { ok[p.first][p.second] = true; }
void dp_calc(vector<pair<int, int> > vl, vector<pair<int, int> > vr) {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < vr.size(); i++) {
    pair<int, int> p = vr[i];
    int s = p.first, t = p.second;
    dp[s][t]++;
  }
  for (int L = vx.size(); L >= 0; L--) {
    for (int i = 0; i + L < vx.size(); i++) {
      int s = i, t = i + L;
      if (t + 1 < vx.size()) dp[s][t] += dp[s][t + 1];
      if (s > 0) dp[s][t] += dp[s - 1][t];
      if (s > 0 && t + 1 < vx.size()) dp[s][t] -= dp[s - 1][t + 1];
    }
  }
  vector<pair<int, int> > ans;
  for (int i = 0; i < vl.size(); i++) {
    pair<int, int> p = vl[i];
    int a = p.first, b = p.second;
    for (int j = 0; j < vl.size(); j++) {
      if (i == j) continue;
      pair<int, int> q = vl[j];
      int c = q.first, d = q.second;
      if (b < c) {
        int zan = dp[b][d] + dp[a][c] - dp[a][d];
        if (zan < dp[b][c]) {
          ins(pair<int, int>(a, d));
        }
      }
    }
  }
}
vector<pair<int, int> > div_conq(vector<pair<int, int> > query) {
  vector<pair<int, int> > ans;
  if (query.empty()) {
    return ans;
  }
  if (query.size() == 1) {
    int id = query[0].second;
    int s = lower_bound(vx.begin(), vx.end(), A[id] - L[id]) - vx.begin();
    int t = lower_bound(vx.begin(), vx.end(), A[id]) - vx.begin();
    int u = lower_bound(vx.begin(), vx.end(), A[id] + L[id]) - vx.begin();
    ans.push_back(pair<int, int>(s, t));
    ans.push_back(pair<int, int>(t, u));
    return ans;
  }
  vector<pair<int, int> > left, right;
  int m = query.size() / 2;
  for (int i = 0; i < m; i++) left.push_back(query[i]);
  for (int i = m; i < query.size(); i++) right.push_back(query[i]);
  vector<pair<int, int> > vl = div_conq(left);
  vector<pair<int, int> > vr = div_conq(right);
  memset(ok, false, sizeof(ok));
  for (int i = 0; i < vx.size(); i++) {
    for (int j = i; j < vx.size(); j++) {
      down[i][j] = -1;
      up[i][j] = 305;
    }
  }
  vector<pair<int, int> > tg;
  for (int i = 0; i < vl.size(); i++) {
    pair<int, int> p = vl[i];
    int a = p.first, b = p.second;
    for (int j = 0; j < vr.size(); j++) {
      pair<int, int> q = vr[j];
      int c = q.first, d = q.second;
      if (a <= c) {
        if (c <= b && b <= d) {
          if (!ok[a][d]) {
            ins(pair<int, int>(a, d));
            tg.push_back(pair<int, int>(a, d));
          }
          down[a][d] = max(down[a][d], c);
          up[a][d] = min(up[a][d], b);
        }
      } else {
        if (d <= b) {
          ins(pair<int, int>(c, b));
        }
      }
    }
  }
  for (int i = 0; i < tg.size(); i++) {
    pair<int, int> p = tg[i];
    int a = p.first, b = p.second;
    for (int j = i + 1; j < tg.size(); j++) {
      pair<int, int> q = tg[j];
      int c = q.first, d = q.second;
      if (a > c) {
        swap(a, c);
        swap(b, d);
      }
      if (up[a][b] < c && b < down[c][d]) {
        ins(pair<int, int>(a, d));
      }
    }
  }
  for (int i = 0; i < vl.size(); i++) ins(vl[i]);
  for (int i = 0; i < vr.size(); i++) ins(vr[i]);
  dp_calc(vl, vr);
  dp_calc(vr, vl);
  for (int i = 0; i < vx.size(); i++) {
    for (int j = i + 1; j < vx.size(); j++) {
      if (ok[i][j]) {
        ans.push_back(pair<int, int>(i, j));
      }
    }
  }
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int> > query;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &A[i], &L[i]);
    vx.push_back(A[i]);
    vx.push_back(A[i] + L[i]);
    vx.push_back(A[i] - L[i]);
    query.push_back(pair<int, int>(A[i], i));
  }
  sort(vx.begin(), vx.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  sort(query.begin(), query.end());
  vector<pair<int, int> > ans = div_conq(query);
  memset(DP, 0, sizeof(DP));
  int now = 0;
  for (int i = 0; i < vx.size(); i++) {
    DP[i + 1] = max(DP[i], DP[i + 1]);
    while (now < ans.size() && ans[now].first == i) {
      DP[ans[now].second + 1] =
          max(DP[ans[now].second + 1],
              DP[i] + vx[ans[now].second] - vx[ans[now].first]);
      now++;
    }
  }
  printf("%d\n", DP[vx.size()]);
  return 0;
}
