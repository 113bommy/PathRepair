#include <bits/stdc++.h>
using namespace std;
const int MAXN = 410;
const int INF = 1 << 30;
int L[MAXN], C[MAXN];
unordered_map<int, int> dp[MAXN];
int gcd(int a, int b) {
  int t;
  while (b) {
    t = a % b;
    a = b;
    b = t;
  }
  return a;
}
vector<pair<int, int> > fact(int x) {
  vector<pair<int, int> > facts;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      int cc = 0;
      while (x % i == 0) {
        x /= i;
        cc++;
      }
      facts.push_back(make_pair(i, cc));
    }
  }
  if (x != 1) {
    facts.push_back(make_pair(x, 1));
  }
  return facts;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &L[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &C[i]);
  }
  for (int i = 0; i < n; i++) {
    dp[i][L[i]] = C[i];
  }
  for (int i = 0; i < n; i++) {
    for (auto it = dp[i].begin(); it != dp[i].end(); ++it) {
      if (i + 1 < n) {
        int t = gcd(it->first, L[i]);
        if (dp[i + 1].count(t) == 0) {
          dp[i + 1][t] = INF;
        }
        dp[i + 1][t] = min(dp[i + 1][t], it->second + C[i]);
      }
      if (dp[i + 1].count(it->first) == 0) {
        dp[i + 1][it->first] = INF;
      }
      dp[i + 1][it->first] = min(dp[i + 1][it->first], it->second);
    }
  }
  if (dp[n].count(1) == 0) {
    printf("-1\n");
  } else {
    printf("%d\n", dp[n][1]);
  }
  return 0;
}
