#include <bits/stdc++.h>
using namespace std;
int n, k, res, a[210], b[210], CNT[2014], CNT1[2014];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i], b[i] = a[i], CNT[a[i] + 1000]++,
                 CNT1[a[i] + 1000] = CNT[a[i] + 1000];
  sort(b + 1, b + n + 1);
  reverse(b + 1, b + n + 1);
  res = -210 * 1000;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (i == j) {
        res = ((res) > (a[i]) ? (res) : (a[i]));
        continue;
      }
      for (int i1 = 0; i1 <= 2000; i1++) CNT1[i1] = CNT[i1];
      vector<int> v;
      int sum = 0;
      for (int p = i; p <= j; p++)
        v.push_back(a[p]), sum += a[p], CNT1[a[p] + 1000]--;
      sort(v.begin(), v.end());
      int J = 0, cnt = 0;
      for (int i1 = 1; i1 <= n && cnt < k; i1++) {
        if (CNT1[b[i1] + 1000] > 0) {
          if (v[J] > b[i1]) break;
          sum -= v[J];
          sum += b[i1];
          CNT1[b[i1] + 1000]--;
          J++;
          cnt++;
          if (j == (int)v.size()) break;
        }
      }
      res = ((res) > (sum) ? (res) : (sum));
    }
  }
  cout << res;
  return 0;
}
