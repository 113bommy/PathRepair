#include <bits/stdc++.h>
using namespace std;
const int maxn = 131072 * 2;
int n;
int first[maxn];
pair<int, int> a[maxn];
int m;
vector<pair<int, int> > q[maxn];
int ans[maxn];
int fen[maxn];
void add(int first) {
  for (first++; first < maxn; first += first & -first) fen[first]++;
}
int get(int k) {
  int ret = 0;
  for (int first = 131072 / 2; first; first >>= 1)
    if (fen[ret + first] < k) {
      ret += first;
      k -= fen[ret];
    }
  return ret;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int second = 0; second < n; second++) {
    cin >> first[second];
    a[second].first = -first[second];
    a[second].second = second;
  }
  sort(a, a + n);
  cin >> m;
  for (int second = 0; second < m; second++) {
    int k, j;
    cin >> k >> j;
    q[k].push_back({second, j});
  }
  for (int second = 0; second < n; second++) {
    add(a[second].second);
    for (pair<int, int> Q : q[second + 1]) ans[Q.first] = get(Q.second);
  }
  for (int second = 0; second < m; second++) cout << first[ans[second]] << endl;
  return 0;
}
