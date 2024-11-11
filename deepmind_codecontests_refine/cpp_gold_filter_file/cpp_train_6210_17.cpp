#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int l[N], r[N];
int sum[N];
int lis[N], lds[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    sum[l[i]]++;
    sum[r[i] + 1]--;
  }
  for (int i = 1; i < N; i++) {
    sum[i] += sum[i - 1];
  }
  {
    set<pair<int, int>> s;
    map<pair<int, int>, int> z;
    for (int i = 1; i <= m; i++) {
      pair<int, int> x = {sum[i], i};
      z[x] = 1;
      if (!s.count(x)) {
        s.insert(x);
        auto it = s.find(x);
        it++;
        if (it != s.end()) {
          z[x] = z[*it];
          s.erase(it);
        } else {
          z[x] = s.size();
        }
      }
      lis[i] = z[x];
    }
  }
  {
    set<pair<int, int>> s;
    map<pair<int, int>, int> z;
    for (int i = m; i >= 1; i--) {
      pair<int, int> x = {sum[i], -i};
      z[x] = 1;
      if (!s.count(x)) {
        s.insert(x);
        auto it = s.find(x);
        it++;
        if (it != s.end()) {
          z[x] = z[*it];
          s.erase(it);
        } else {
          z[x] = s.size();
        }
      }
      lds[i] = z[x];
    }
  }
  int ans = 1;
  for (int i = 1; i <= m; i++) {
    ans = max(ans, lis[i] + lds[i] - 1);
  }
  cout << ans << endl;
  return 0;
}
