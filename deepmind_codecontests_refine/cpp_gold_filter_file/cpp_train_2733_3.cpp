#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1), eps = 1e-8;
const int maxn = 1 << 17;
const int N = 1e3 + 10, M = 1e7 + 10, mod = 998244353;
int n, m;
int a[N];
bitset<1001> b[N];
int num[N];
vector<int> G[N];
vector<pair<int, int> > ans;
bool cmp(int x, int y) {
  if (a[x] == a[y]) return x > y;
  return a[x] > a[y];
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    num[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[i] > a[j]) {
        G[i].push_back(j);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    sort(G[i].begin(), G[i].end(), cmp);
    for (int j = 0; j < G[i].size(); j++) {
      int x = G[i][j];
      ans.push_back(pair<int, int>(i, x));
      swap(num[i], num[x]);
    }
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
