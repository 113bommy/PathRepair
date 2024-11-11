#include <bits/stdc++.h>
using namespace std;
int dp[5555][5555], val[5555], ch[5555][5555], dp2[5555], arr[1111111];
vector<pair<int, int> > v[5555];
set<int> s;
int main(void) {
  for (int e = 2; e <= 5000; e++) {
    vector<pair<int, int> > v2;
    int tmp = e;
    for (int p = 2; p <= sqrt(e); p++) {
      int num = 0;
      while (tmp % p == 0) {
        tmp /= p;
        num++;
      }
      if (num) v2.push_back(make_pair(p, num));
    }
    if (tmp != 1) v2.push_back(make_pair(tmp, 1));
    for (int p = 0; p < v2.size(); p++) ch[e][v2[p].first] += v2[p].second;
    int tot = 0;
    for (int p = 0; p <= 5000; p++) {
      ch[e][p] += ch[e - 1][p];
      if (ch[e][p]) v[e].push_back(make_pair(p, ch[e][p]));
      tot += ch[e][p];
    }
    val[e] = tot;
  }
  for (int p = 2; p <= 5000; p++) {
    dp[1][p] = val[p];
  }
  for (int e = 2; e <= 5000; e++) {
    vector<pair<int, int> > v2;
    for (int p = 0; p < v[e].size(); p++) v2.push_back(v[e][p]);
    int now = val[e];
    for (int p = e + 1; p <= 5000; p++) {
      int tot = 0, la = v[p].size() - 1;
      for (int q = v2.size() - 1; q >= 0; q--) {
        if (v2[q].first != v[p][la].first) break;
        if (v2[q].first == v[p][la].first) {
          tot += min(v2[q].second, v[p][la].second);
          if (v2[q].second != v[p][la].second) break;
        }
        la--;
      }
      dp[e][p] = val[e] + val[p] - tot * 2;
    }
  }
  long long int ans = 1e18;
  int n;
  scanf("%d", &n);
  for (int e = 0; e < n; e++) {
    int r;
    scanf("%d", &r);
    arr[e] = r;
    if (r == 0) r = 1;
    dp2[r]++;
  }
  if (n <= 50) {
    for (int e = 0; e < n; e++) {
      for (int p = e + 1; p < n; p++) {
        int f = arr[e], s = arr[p];
        if (f == 1 || s == 1) continue;
        vector<pair<int, int> > v2;
        int tot = 0, la = v[s].size() - 1;
        for (int q = v[f].size() - 1; q >= 0; q--) {
          if (la == -1) break;
          if (v[f][q].first != v[s][la].first)
            break;
          else {
            int vn = min(v[f][q].second, v[s][la].second);
            v2.push_back(make_pair(v[f][q].first, vn));
            tot += vn;
            if (v[f][q].second != v[s][la].second) break;
          }
          la--;
        }
        long long int tot2 = val[f] + val[s] - tot * 2;
        sort(v2.begin(), v2.end());
        for (int q = 0; q < n; q++) {
          if (q == e || q == p) continue;
          int r = arr[q];
          int tot3 = 0, la = v[r].size() - 1;
          for (int t = v2.size() - 1; t >= 0; t--) {
            if (la == -1) break;
            if (v2[t].first != v[r][la].first)
              break;
            else {
              tot3 += min(v2[t].second, v[r][la].second);
              if (v2[t].second != v[r][la].second) break;
            }
            la--;
          }
          tot2 += tot + val[r] - tot3 * 2;
        }
        ans = min(ans, tot2);
      }
    }
  }
  for (int e = 1; e <= 5000; e++) {
    long long int tot = 0;
    for (int q = 1; q <= 5000; q++) {
      int f = min(e, q), s = max(e, q);
      tot += (long long int)dp2[q] * (long long int)dp[f][s];
    }
    ans = min(ans, tot);
  }
  printf("%lld", ans);
  return 0;
}
