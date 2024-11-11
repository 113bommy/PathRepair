#include <bits/stdc++.h>
using namespace std;
int n, m, k, s;
int a[200005];
int ad[200005];
int b[200005];
int bd[200005];
int t[200005];
int c[200005];
long long dp[2][200005];
int dpcnt[2];
int dcnt;
int C(int _n) {
  for (int i = max(0, k - dpcnt[1]); i <= k && i <= dpcnt[0]; i++) {
    if ((long long)dp[0][i] * (long long)a[_n] +
            (long long)dp[1][k - i] * (long long)b[_n] <=
        (long long)s) {
      dcnt = i;
      return 1;
    }
  }
  return 0;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &s);
  for (int(i) = (0); ((i)) < ((n)); ++(i)) scanf("%d", a + i);
  for (int(i) = (0); ((i)) < ((n - 1)); ++(i)) {
    if (a[i + 1] > a[i])
      ad[i + 1] = ad[i];
    else
      ad[i + 1] = i + 1;
    a[i + 1] = min(a[i + 1], a[i]);
  }
  for (int(i) = (0); ((i)) < ((n)); ++(i)) scanf("%d", b + i);
  for (int(i) = (0); ((i)) < ((n - 1)); ++(i)) {
    if (b[i + 1] > b[i])
      bd[i + 1] = bd[i];
    else
      bd[i + 1] = i + 1;
    b[i + 1] = min(b[i + 1], b[i]);
  }
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      dollarq;
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      poundq;
  for (int(i) = (0); ((i)) < ((m)); ++(i)) {
    scanf("%d%d", t + i, c + i);
    if (t[i] == 1)
      dollarq.push(make_pair(c[i], i));
    else {
      poundq.push(make_pair(c[i], i));
    }
    dpcnt[t[i] - 1]++;
    dp[t[i] - 1][dpcnt[t[i] - 1]] = c[i];
  }
  sort(dp[0], dp[0] + dpcnt[0] + 1);
  sort(dp[1], dp[1] + dpcnt[1] + 1);
  for (int(i) = (0); ((i)) < ((m)); ++(i)) {
    dp[0][i + 1] += dp[0][i];
    dp[1][i + 1] += dp[1][i];
  }
  int ub = n, lb = 0;
  int mid;
  int res = -1;
  int itr = 100;
  while (itr--) {
    mid = (ub + lb) / 2;
    if (C(mid)) {
      ub = mid;
      res = mid;
    } else
      lb = mid;
  }
  if (res == -1)
    puts("-1");
  else {
    printf("%d\n", res + 1);
    priority_queue<pair<int, int>, vector<pair<int, int> >,
                   greater<pair<int, int> > >
        pq;
    for (int i = 0; i < dcnt; i++) {
      pair<int, int> p = dollarq.top();
      dollarq.pop();
      printf("%d %d\n", p.second + 1, ad[res] + 1);
    }
    for (int i = 0; i < k - dcnt; i++) {
      pair<int, int> p = poundq.top();
      poundq.pop();
      printf("%d %d\n", p.second + 1, bd[res] + 1);
    }
  }
  return 0;
}
