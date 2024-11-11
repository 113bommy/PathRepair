#include <bits/stdc++.h>
using namespace std;
int a, b, i, j, n, m, z, k, mark[100005];
pair<pair<int, int>, int> p[100005];
pair<int, int> answ[100005];
vector<int> g;
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &a, &b);
    p[i] = make_pair(make_pair(a, b ^ 1), i);
  }
  sort(p + 1, p + m + 1);
  z = 2;
  a = 2;
  b = 3;
  for (i = 1; i <= m; i++) {
    if (k == 0 && p[i].first.second == 1) {
      cout << -1 << endl;
      return 0;
    }
    if (p[i].first.second == 0) {
      answ[p[i].second] = make_pair(1, z);
      k += z - 2;
      z++;
      g.push_back(z);
      mark[z] = 2;
    } else {
      a = g.front();
      b = mark[a];
      answ[p[i].second] = make_pair(b, a);
      k--;
      mark[a]++;
      if (mark[a] == a) g.erase(g.begin());
    }
  }
  for (i = 1; i <= m; i++) printf("%d %d\n", answ[i].first, answ[i].second);
  return 0;
}
