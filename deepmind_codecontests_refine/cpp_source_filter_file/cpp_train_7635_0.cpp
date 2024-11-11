#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);
int n, k[2000];
vector<int> v[2000];
int calc(vector<int> &v, int down, int up) {
  int l = 0, r = (int)v.size() - 1;
  int L = (int)v.size();
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (v[mid] > down) {
      L = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  int R = -1;
  l = 0;
  r = (int)v.size() - 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (v[mid] < up) {
      R = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return max(0, R - L + 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", k + i);
    for (int j = 0, x; j < k[i]; j++) {
      scanf("%d", &x);
      v[i].push_back(x);
    }
    sort(v[i].begin(), v[i].end());
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < k[i]; j++) {
      int k1 = calc(v[(i + n - 1) % n], v[i][j - 1], v[i][j]);
      int k2 = calc(v[(i + n + 1) % n], v[i][j - 1], v[i][j]);
      ans += k1 == k2;
    }
  }
  cout << ans << endl;
  return 0;
}
