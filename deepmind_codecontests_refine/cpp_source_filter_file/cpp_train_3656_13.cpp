#include <bits/stdc++.h>
using namespace std;
const int Maxn = 5015;
const int Maxm = 505;
const int Inf = 1000000000;
int s, d;
vector<pair<int, int> > toup[Maxm];
int has[Maxn][Maxm];
int main() {
  scanf("%d %d", &d, &s);
  for (int i = 0; i < d; i++)
    for (int j = 0; j < 10; j++) {
      int nw = (10 * i + j) % d;
      toup[nw].push_back(pair<int, int>(i, j));
    }
  fill((int*)has, (int*)has + Maxn * Maxm, Inf);
  has[0][0] = 0;
  priority_queue<pair<int, pair<int, int> > > Q;
  Q.push(pair<int, pair<int, int> >(0, pair<int, int>(0, 0)));
  while (!Q.empty()) {
    pair<int, int> v = Q.top().second;
    int d = -Q.top().first;
    Q.pop();
    if (has[v.first][v.second] != d) continue;
    for (int i = 0; i < toup[v.second].size(); i++) {
      pair<int, int> u = toup[v.second][i];
      pair<int, int> nxt = pair<int, int>(v.first + u.second, u.first);
      if (nxt.first <= s && d + 1 < has[nxt.first][nxt.second]) {
        has[nxt.first][nxt.second] = d + 1;
        Q.push(pair<int, pair<int, int> >(-has[nxt.first][nxt.second], nxt));
      }
    }
  }
  if (has[s][0] >= Inf) {
    printf("-1\n");
    return 0;
  }
  int a = s, b = 0;
  while (a > 0) {
    int my = has[a][b];
    for (int i = 0;; i++)
      if (has[a - i][(10 * b + i) % d] == my - 1) {
        printf("%d", i);
        a -= i;
        b = (10 * b + i) % d;
        break;
      }
  }
  printf("\n");
  return 0;
}
