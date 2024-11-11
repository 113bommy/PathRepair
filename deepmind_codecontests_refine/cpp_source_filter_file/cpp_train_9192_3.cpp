#include <bits/stdc++.h>
using namespace std;
vector<int> adj[205];
int l[205] = {0}, r[205] = {0}, ret = 0, Max1 = 0, Max2 = 0, tmp, n, i, a, b,
    M = 0, Mxx = 0;
int wak(int nod, int pro) {
  int ret, M1 = 0, M2 = 0;
  if (adj[nod].size() == 1)
    return 0;
  else {
    for (int i = 0; i < adj[nod].size(); i++) {
      if (adj[nod][i] == pro) continue;
      ret = wak(adj[nod][i], nod);
      if (ret > M2) M2 = ret;
      if (M2 > M1) {
        tmp = M2;
        M2 = M1;
        M1 = tmp;
      }
    }
    Mxx = max(Mxx, M2 + M1);
    return 1 + M1;
  }
}
int calc(int nod, int pro) {
  int Max1 = 0, aa;
  int Max2 = 0;
  Mxx = 0;
  if (adj[nod].size() == 1) return 0;
  if (adj[nod].size() == 2) {
    for (int i = 0; i < adj[nod].size(); i++) {
      if (adj[nod][i] != pro) {
        aa = 1 + wak(adj[nod][i], nod);
        return max(aa, Mxx);
      }
    }
  }
  if (adj[nod].size() >= 3) {
    for (int i = 0; i < adj[nod].size(); i++) {
      if (adj[nod][i] != pro) {
        ret = wak(adj[nod][i], nod);
        if (ret > Max2) Max2 = ret;
        if (Max2 > Max1) {
          tmp = Max1;
          Max1 = Max2;
          Max2 = tmp;
        }
      }
    }
    return max(2 + Max1 + Max2, Mxx);
  }
}
int main() {
  scanf("%d", &n);
  for (i = 1; i < n; i++) {
    scanf("%d %d", &l[i], &r[i]);
    adj[l[i]].push_back(r[i]);
    adj[r[i]].push_back(l[i]);
  }
  for (i = 1; i < n; i++) {
    a = calc(l[i], r[i]);
    b = calc(r[i], l[i]);
    M = max(M, a * b);
  }
  printf("%d", M);
  return 0;
}
