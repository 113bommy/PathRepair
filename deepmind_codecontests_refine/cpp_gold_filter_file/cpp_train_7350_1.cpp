#include <bits/stdc++.h>
using namespace std;
const int N = 500;
pair<int, int> coo[N];
int n, m, k;
int fix(int a, int b) { return min(a, b); }
int sum[4 * N + 5][4 * N + 5];
bool check(int mid) {
  vector<int> vx, vy;
  vx.push_back(1);
  vx.push_back(n);
  vy.push_back(1);
  vy.push_back(m);
  memset(sum, 0, sizeof sum);
  for (int i = 0; i < k; i++) {
    vx.push_back(min(coo[i].first + mid, n));
    vy.push_back(min(coo[i].second + mid, m));
    vx.push_back(max(coo[i].first - mid, 1));
    vy.push_back(max(coo[i].second - mid, 1));
    vx.push_back(min(coo[i].first + mid + 1, n));
    vy.push_back(min(coo[i].second + mid + 1, m));
    vx.push_back(max(coo[i].first - mid - 1, 1));
    vy.push_back(max(coo[i].second - mid - 1, 1));
  }
  sort(vx.begin(), vx.end());
  sort(vy.begin(), vy.end());
  vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
  vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
  for (int i = 0; i < k; i++) {
    int a = lower_bound(vx.begin(), vx.end(), min(coo[i].first + mid, n)) -
            vx.begin() + 1;
    int b = lower_bound(vy.begin(), vy.end(), min(coo[i].second + mid, m)) -
            vy.begin() + 1;
    int c = lower_bound(vx.begin(), vx.end(), max(coo[i].first - mid, 1)) -
            vx.begin() + 1;
    int d = lower_bound(vy.begin(), vy.end(), max(coo[i].second - mid, 1)) -
            vy.begin() + 1;
    sum[c][d]++;
    sum[c][b + 1]--;
    sum[a + 1][d]--;
    sum[a + 1][b + 1]++;
  }
  int mxx = 0, mnx = 1e9, mxy = 0, mny = 1e9;
  for (int i = 1; i <= vx.size(); i++)
    for (int j = 1; j <= vy.size(); j++) {
      sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
      if (sum[i][j]) continue;
      mxx = max(mxx, vx[i - 1]);
      mnx = min(mnx, vx[i - 1]);
      mxy = max(mxy, vy[j - 1]);
      mny = min(mny, vy[j - 1]);
    }
  if (!mxx) return true;
  return max(abs(mxx - mnx), abs(mxy - mny) + 1) / 2 <= mid;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; i++) scanf("%d%d", &coo[i].first, &coo[i].second);
  int l = 0, r = 1e9;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  cout << l << endl;
}
