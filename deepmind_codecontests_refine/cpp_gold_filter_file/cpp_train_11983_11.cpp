#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
map<vector<int>, pair<int, int> > m;
vector<pair<int, int> > ans;
int a[N];
void inv(int i, int j) {
  a[i] = 1 - a[i];
  a[j] = 1 - a[j];
  a[(i + j) / 2] = 1 - a[(i + j) / 2];
}
void inV(vector<int> &a, int i, int j) {
  a[i] = 1 - a[i];
  a[j] = 1 - a[j];
  a[(i + j) / 2] = 1 - a[(i + j) / 2];
}
int main() {
  int i, j, k, n, i1, j1, l;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (i = 1; i <= n; ++i) cin >> a[i];
  for (i = n; i > 11; --i) {
    if (a[i] > 0)
      if (a[i - 1] + a[i - 2] == 0) {
        inv(i, i - 6);
        ans.push_back({i, i - 6});
      } else if (a[i - 1] + a[i - 2] == 2) {
        inv(i, i - 2);
        ans.push_back({i, i - 2});
      } else if (a[i - 2] == 1) {
        inv(i, i - 4);
        ans.push_back({i, i - 4});
      } else {
        bool can = false;
        for (j = i - 5; j < i; ++j)
          for (i1 = i - 4; i1 < i; ++i1)
            for (j1 = i - 5; j1 < i1; ++j1)
              if (!can) {
                inv(i, 2 * j - i);
                inv(i1, 2 * j1 - i1);
                if (2 * j1 - i1 > i1) exit(1);
                can = true;
                for (l = i - 5; l <= i; ++l)
                  if (a[l] == 1) can = false;
                if (can) {
                  ans.push_back({i, 2 * j - i});
                  ans.push_back({i1, 2 * j1 - i1});
                } else {
                  inv(i, 2 * j - i);
                  inv(i1, 2 * j1 - i1);
                }
              }
        if (!can) {
          for (l = i - 5; l <= i; ++l) cout << a[l] << ' ';
          return 0;
        }
      }
  }
  for (i = 12; i <= n; ++i)
    if (a[i] != 0) exit(0);
  vector<int> v, p;
  vector<vector<int> > q;
  for (i = 1; i <= min(n, 11); ++i) {
    v.push_back(a[i]);
    p.push_back(0);
  }
  m[p] = {0, 0};
  q.push_back(p);
  for (i = 0; i < q.size(); ++i) {
    for (j = 0; j < q[i].size(); ++j)
      for (l = j + 2; l < q[i].size(); l += 2) {
        vector<int> K;
        for (i1 = 0; i1 < q[i].size(); ++i1) K.push_back(q[i][i1]);
        inV(K, j, l);
        if (m.count(K) == 0) {
          m[K] = {j, l};
          q.push_back(K);
        }
      }
  }
  if (m.count(v) == 0) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  while (v != p) {
    ans.push_back({m[v].first + 1, m[v].second + 1});
    inV(v, m[v].first, m[v].second);
  }
  cout << ans.size() << endl;
  for (i = 0; i < ans.size(); ++i) {
    if (ans[i].second < ans[i].first) swap(ans[i].first, ans[i].second);
    cout << ans[i].first << ' ' << (ans[i].first + ans[i].second) / 2 << ' '
         << ans[i].second << endl;
  }
}
