#include <bits/stdc++.h>
using namespace std;
const int N = 310000;
int n, m, a[N], b[N], p[N], smax[N], rnext[N];
vector<int> v[N];
priority_queue<int> q;
void calc() {
  smax[n] = a[n];
  for (int i = n - 1; i >= 1; i--) {
    smax[i] = max(smax[i + 1], a[i]);
  }
  for (int i = 1; i <= m; i++) {
    int l = 1, r = n;
    rnext[i] = -1;
    while (l + 1 < r) {
      int mid = (l + r) / 2;
      if (smax[mid] >= b[i])
        l = mid;
      else
        r = mid - 1;
    }
    if (smax[r] >= b[i])
      rnext[i] = r;
    else if (smax[l] >= b[i])
      rnext[i] = l;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &p[i]);
  calc();
  for (int i = 1; i <= m; i++) {
    if (rnext[i] != -1) v[rnext[i]].push_back(p[i]);
  }
  for (int i = 1; i <= n; i++) {
    sort(v[i].begin(), v[i].end());
  }
  int ans = 0;
  long long cur = 0;
  for (int i = 1; i <= n; i++) {
    cur += a[i];
    for (int j = 0; j < v[i].size(); j++) {
      if (cur >= v[i][j]) {
        cur -= v[i][j];
        q.push(v[i][j]);
        ans++;
      } else {
        if (!q.empty()) {
          int t = q.top();
          if (t <= v[i][j]) break;
          cur += t - v[i][j];
          q.pop();
          q.push(v[i][j]);
        }
      }
    }
  }
  cout << ans;
  return 0;
}
