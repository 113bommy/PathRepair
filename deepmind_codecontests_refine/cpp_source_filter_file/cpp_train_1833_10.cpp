#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int d;
  cin >> d;
  int n, m;
  cin >> n >> m;
  vector<int> xc_1(n + 2, 0);
  vector<int> xc_2(n + 2, 0);
  vector<int> xc_less(n + 2, 0);
  vector<int> xc_more(n + 2, 0);
  vector<int> yc_1(m + 2, 0);
  vector<int> yc_2(m + 2, 0);
  vector<int> yc_less(m + 2, 0);
  vector<int> yc_more(m + 2, 0);
  vector<pair<int, int>> sof_1;
  vector<pair<int, int>> sof_2;
  int i;
  int x1, x2, y1, y2;
  for (i = 0; i < d; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    xc_1[x1]++;
    xc_2[x2]++;
    yc_1[y1]++;
    yc_2[y2]++;
    xc_more[min(x1, x2)]++;
    xc_less[max(x1, x2)]++;
    yc_more[min(y1, y2)]++;
    yc_less[max(y1, y2)]++;
    sof_1.push_back({x1, y1});
    sof_2.push_back({x2, y2});
  }
  for (i = 1; i <= n; i++) {
    xc_1[i] += xc_1[i - 1];
    xc_2[i] += xc_2[i - 1];
    xc_less[i] += xc_less[i - 1];
  }
  for (i = n; i >= 1; i--) {
    xc_more[i] += xc_more[i + 1];
  }
  for (i = 1; i <= m; i++) {
    yc_1[i] += yc_1[i - 1];
    yc_2[i] += yc_2[i - 1];
    yc_less[i] += yc_less[i - 1];
  }
  for (i = n; i >= 1; i--) {
    yc_more[i] += yc_more[i + 1];
  }
  int lf, rt, up, dw;
  cin >> lf >> rt >> up >> dw;
  int ans = -1;
  for (i = 0; i < d; i++) {
    x1 = sof_1[i].first;
    y1 = sof_1[i].second;
    x2 = sof_2[i].first;
    y2 = sof_2[i].second;
    int clf = 0, crt = 0, cup = 0, cdw = 0;
    if (x1 == x2) {
      if (y1 > y2) {
        swap(y1, y2);
      }
      clf = xc_1[x1 - 1] + xc_2[x1 - 1] - xc_less[x1 - 1];
      crt = d - xc_1[x1] + d - xc_2[x1] - xc_more[x1 + 1];
      cup = yc_1[y1] + yc_2[y1] - yc_less[y1] - 1;
      cdw = d - yc_1[y1] + d - yc_2[y1] - yc_more[y2] - 1;
    } else {
      if (x1 > x2) {
        swap(x1, x2);
      }
      cup = yc_1[y1 - 1] + yc_2[y1 - 1] - yc_less[y1 - 1];
      cdw = d - yc_1[y2] + d - yc_2[y2] - yc_more[y2 + 1];
      clf = xc_1[x1] + xc_2[x1] - xc_less[x1] - 1;
      crt = d - xc_1[x1] + d - xc_2[x1] - xc_more[x2] - 1;
    }
    if (lf == clf && rt == crt && cup == up && cdw == dw) {
      ans = i + 1;
    }
  }
  cout << ans;
  return 0;
}
