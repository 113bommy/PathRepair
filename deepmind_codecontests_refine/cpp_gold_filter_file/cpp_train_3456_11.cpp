#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int T, n, m[N], p[N];
vector<int> v[N];
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i <= n - 1; i++) v[i].clear();
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &m[i], &p[i]);
      v[m[i]].push_back(p[i]);
    }
    int pre = n, cnt = 0;
    long long res = 0;
    multiset<int> s;
    for (int i = n - 1; i >= 0; i--) {
      pre -= v[i].size();
      for (int j = 0; j < v[i].size(); j++) s.insert(v[i][j]);
      int need = i - pre;
      while (cnt < need) {
        ++cnt;
        res += *s.begin();
        s.erase(s.begin());
      }
    }
    printf("%lld\n", res);
  }
  return 0;
}
