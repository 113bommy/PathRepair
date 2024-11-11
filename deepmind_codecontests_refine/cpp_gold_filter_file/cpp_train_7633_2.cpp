#include <bits/stdc++.h>
using namespace std;
int n, m;
int t[1001000];
int ans[1001000];
int x[1001000];
vector<pair<int, int> > v;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> x[i];
  }
  int t0 = 0;
  int pr = -1;
  for (int i = 0; i < n; i++) {
    if (i == n - 1 || (i + 1) % m == 0) {
      for (int j = pr + 1; j <= i; j++) {
        v.push_back(make_pair(x[j], j));
      }
      t0 = max(t0, t[i]);
      stable_sort(v.begin(), v.end());
      int pr0 = -1;
      for (int j = 0; j < v.size(); j++) {
        if (j == v.size() - 1 || v[j].first != v[j + 1].first) {
          t0 = t0 + v[j].first - (pr0 >= 0 ? v[pr0].first : 0);
          for (int k = pr0 + 1; k <= j; k++) {
            ans[v[k].second] = t0;
          }
          t0 += (1 + (j - pr0) / 2);
          pr0 = j;
        }
      }
      t0 += v[v.size() - 1].first;
      pr = i;
      v.clear();
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d%c", ans[i], " \n"[i == n - 1]);
  }
  return 0;
}
