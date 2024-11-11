#include <bits/stdc++.h>
using namespace std;
vector<int> G[100010];
int T[100010];
vector<pair<int, int> > sol;
vector<pair<int, int> > muchii;
int K;
int n;
bool viz[100010];
void df(int x) {
  viz[x] = 1;
  T[x] = -1;
  for (typeof(G[x].begin()) i = G[x].begin(); i != G[x].end(); i++) {
    if (!viz[*i]) {
      df(*i);
      K++;
      if (T[x] == -1) {
        T[x] = K;
      } else {
        muchii.push_back(make_pair(T[x], K));
      }
      if (T[*i] != -1) muchii.push_back(make_pair(K, T[*i]));
      sol.push_back(make_pair(x, *i));
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
  df(1);
  printf("%d\n", sol.size());
  for (typeof(sol.begin()) i = sol.begin(); i != sol.end(); i++) {
    printf("2 %d %d\n", i->first, i->second);
  }
  for (typeof(muchii.begin()) i = muchii.begin(); i != muchii.end(); i++) {
    printf("%d %d\n", i->first, i->second);
  }
  return 0;
}
