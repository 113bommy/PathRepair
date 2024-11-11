#include <bits/stdc++.h>
using namespace std;
int n, w[1005], h[1005], hh, ans = 1e9, sum;
bool cmp(int x, int y) { return w[x] - h[x] > w[y] - h[y]; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &w[i], &h[i]);
    sum += w[i];
    hh = max(w[i], max(hh, h[i]));
  }
  for (int i = 1; i <= hh; i++) {
    int cnt = 0, now = sum;
    vector<int> v;
    for (int j = 1; j <= n; j++) {
      if (w[j] > i && h[j] > i) {
        cnt = 1e9;
        break;
      } else if (w[j] > i && h[j] <= i)
        continue;
      else if (w[j] <= i && h[j] > i) {
        now += h[j] - w[j];
        cnt++;
      } else if (w[j] > h[j])
        v.push_back(j);
    }
    if (cnt > n / 2) continue;
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size() && cnt + i < n / 2; i++)
      now += h[v[i]] - w[v[i]];
    ans = min(ans, now * i);
  }
  printf("%d", ans);
}
