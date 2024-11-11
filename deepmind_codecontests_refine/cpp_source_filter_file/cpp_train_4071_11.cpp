#include <bits/stdc++.h>
using namespace std;
int n, m;
int x;
long long y;
vector<long long> a[3005], g;
int num[3005];
int sum[3005][3005];
int main() {
  cin >> n >> m;
  int mx = 0;
  for (int i = 0; i < n; i++) a[i].clear();
  memset(num, 0, sizeof num);
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    num[x]++;
    a[x].push_back(y);
    if (num[x] > mx && x != 1) mx = num[x];
  }
  for (int i = 2; i <= m; i++) {
    if (a[i].size()) {
      sort(a[i].begin(), a[i].end());
      sum[i][0] = a[i][0];
      for (int j = 1; j < num[i]; j++) sum[i][j] = sum[i][j - 1] + a[i][j];
    }
  }
  if (num[1] > mx) {
    cout << 0 << endl;
    return 0;
  }
  long long sss = (1LL << (62));
  for (int i = m; i >= 0; i--) {
    g.clear();
    long long tot = num[1];
    int hh = 0;
    long long res = 0;
    for (int j = 2; j <= m; j++) {
      if (num[j] > i) {
        tot += num[j] - i;
        res += sum[j][num[j] - i - 1];
        for (int k = num[j] - i; k < num[j]; k++) g.push_back(a[j][k]);
        hh = max(hh, i);
      } else {
        for (int k = 0; k < num[j]; k++) g.push_back(a[j][k]);
        hh = max(hh, num[j]);
      }
    }
    if (tot <= hh) {
      sort(g.begin(), g.end());
      for (int j = 0; j < (int)g.size(); j++) {
        res += g[j];
        ++tot;
        if (tot > hh) break;
      }
    }
    if (tot > hh) sss = min(sss, res);
  }
  cout << sss << endl;
}
