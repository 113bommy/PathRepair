#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int N = 1005;
int w[N], h[N];
bool cmp(const int &x, const int &y) { return x > y; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) cin >> h[i] >> w[i];
  int ans = INF;
  for (int i = 1; i <= 1000; i++) {
    vector<int> a;
    bool flag = false;
    int sumh = 0, sum = 0;
    for (int j = 0; j < n; j++) {
      if (i < w[j] && i < h[j]) {
        flag = true;
        break;
      }
      if (i < w[j] && i >= h[j]) {
        sum++;
        sumh += w[j];
      } else if (i >= w[j] && i >= h[j] && h[j] >= w[j]) {
        sumh += h[j];
        a.push_back(h[j] - w[j]);
      } else
        sumh += h[j];
      if (sum > n / 2) {
        flag = true;
        break;
      }
    }
    if (flag) continue;
    sort(a.begin(), a.end(), cmp);
    int sz = a.size();
    for (int j = 0; j < min(sz, n / 2 - sum); j++) sumh -= a[j];
    ans = min(ans, i * sumh);
  }
  cout << ans << endl;
  return 0;
}
