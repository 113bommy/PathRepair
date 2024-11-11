#include <bits/stdc++.h>
using namespace std;
class compare {
 public:
  bool operator()(int x, int y) { return x > y; }
};
int in[100010], ans[100010];
set<int, compare> ms;
set<int>::iterator it;
vector<int> mat[100010];
int main() {
  ios::sync_with_stdio(false);
  int i, j, n, m, a, b, c, d, p;
  cin >> n >> m;
  d = n;
  for (int i = 0; i <= m - 1; i++) {
    cin >> a >> b;
    mat[b].push_back(a);
    in[a]++;
  }
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0) ms.insert(i);
  }
  while (!ms.empty()) {
    it = ms.begin();
    ms.erase(ms.begin());
    p = *it;
    ans[p] = d;
    d--;
    for (int i = 0; i <= (int)mat[p].size() - 1; i++) {
      int x = mat[p][i];
      in[x]--;
      if (in[x] == 0) ms.insert(x);
    }
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  return 0;
}
