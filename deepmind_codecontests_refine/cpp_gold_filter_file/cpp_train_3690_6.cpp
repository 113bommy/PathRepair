#include <bits/stdc++.h>
using namespace std;
int n, m, cnt[100001], t[100001], inSet[100001];
vector<int> gf[100001];
vector<pair<int, int> > v;
int findRoot(int x) {
  int x2 = x;
  for (; t[x] != 0; x = t[x])
    ;
  for (; x2 != x;) {
    int temp = t[x2];
    t[x2] = x;
    x2 = temp;
  }
  return x;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    v.push_back(make_pair(x, i));
  }
  for (; m; --m) {
    int x, y;
    cin >> x >> y;
    gf[x].push_back(y);
    gf[y].push_back(x);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  long long totalSum = 0LL;
  for (int i = 1; i <= n; ++i) cnt[i] = 1, t[i] = 0;
  for (int i = 0; i < n; ++i) {
    int currNode = v[i].second;
    inSet[currNode] = 1;
    for (int j = 0; j < (int)gf[currNode].size(); ++j) {
      int currNeigh = gf[currNode][j];
      if (inSet[currNeigh] == 1) {
        int rootOfCurrNode = findRoot(currNode);
        int rootOfNeigh = findRoot(currNeigh);
        if (rootOfCurrNode != rootOfNeigh) {
          totalSum += 1LL * v[i].first * cnt[rootOfNeigh] * cnt[rootOfCurrNode];
          t[rootOfCurrNode] = rootOfNeigh;
          cnt[rootOfNeigh] += cnt[rootOfCurrNode];
          cnt[rootOfCurrNode] = 0;
        }
      }
    }
  }
  double res = totalSum * 2.0 / (1LL * n * (n - 1));
  cout << fixed << setprecision(4) << res;
}
