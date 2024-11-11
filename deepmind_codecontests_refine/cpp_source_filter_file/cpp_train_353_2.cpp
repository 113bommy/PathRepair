#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXV = 3 * MAXN;
const int INF = 0x01010101;
bool compx(pair<int, int> p1, pair<int, int> p2) {
  p1.second *= -1;
  p2.second *= -1;
  return p1 < p2;
}
bool compy(pair<int, int> p1, pair<int, int> p2) {
  return pair<int, int>(p1.second, -p1.first) <
         pair<int, int>(p2.second, -p2.first);
}
int N;
int A[3][MAXN];
int M;
vector<int> vals;
int fst[MAXV][3];
int ind[MAXV];
int main() {
  scanf("%d", &N);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &A[i][j]);
      vals.push_back(A[i][j]);
    }
  }
  sort((vals).begin(), (vals).end());
  vals.resize(unique((vals).begin(), (vals).end()) - vals.begin());
  M = vals.size();
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < 3; j++) {
      fst[i][j] = INF;
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < N; j++) {
      int &x = A[i][j];
      x = lower_bound((vals).begin(), (vals).end(), x) - vals.begin();
      fst[x][i] = min(fst[x][i], j + 1);
    }
  }
  iota(ind, ind + M, 0);
  sort(ind, ind + M, [](int x, int y) { return fst[x][0] > fst[y][0]; });
  int ans = fst[ind[0]][0];
  set<pair<int, int> > st = {pair<int, int>(0, 2 * INF),
                             pair<int, int>(2 * INF, 0)};
  multiset<int> mst = {0};
  for (int i = 0; i < M; i++) {
    int x = fst[ind[i]][1], y = fst[ind[i]][2];
    set<pair<int, int> >::iterator lt, it,
        rt = st.lower_bound(pair<int, int>(x, y));
    assert(rt != st.end());
    if (rt->second < y) {
      it = st.insert(pair<int, int>(x, y)).first;
      lt = prev(it);
      mst.erase(mst.find(lt->first + rt->second));
      mst.insert(it->first + rt->second);
      while (lt->second < it->second) {
        rt = lt--;
        mst.erase(mst.find(lt->first + rt->second));
        st.erase(rt);
      }
      mst.insert(lt->first + it->second);
    }
    ans = min(ans, fst[ind[i + 1]][0] + *mst.begin());
  }
  printf("%d\n", ans);
}
