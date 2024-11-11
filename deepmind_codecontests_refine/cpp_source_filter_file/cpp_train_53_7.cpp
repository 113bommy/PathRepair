#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int IT_MAX = 1 << 17;
const long long MOD = 1000000007;
const int INF = 1034567890;
const long long LL_INF = 1234567890123456789ll;
const double PI = acos(-1);
const long double ERR = 1E-10;
int r[1050][2];
int root(int x) {
  if (r[x][0] == x) return r[x][0];
  int t = r[x][0];
  r[x][0] = root(r[x][0]);
  r[x][1] ^= r[t][1];
  return r[x][0];
}
pair<pair<int, int>, pair<int, int> > in[500050];
int main() {
  int N, Q, M, i, j, t1, t2, t3, S, E;
  scanf("%d %d %d", &N, &M, &Q);
  for (i = 1; i <= M; i++) {
    scanf("%d %d %d", &t1, &t2, &t3);
    in[i] = make_pair(pair<int, int>(t3, i), pair<int, int>(t1, t2));
  }
  sort(in + 1, in + M + 1);
  while (Q--) {
    scanf("%d %d", &S, &E);
    for (i = 1; i <= N; i++) r[i][0] = i, r[i][1] = 1;
    for (i = M; i >= 1; i--) {
      if (in[i].first.second < S || in[i].first.second > E) continue;
      t1 = in[i].second.first;
      t2 = in[i].second.second;
      int u1 = root(t1);
      int u2 = root(t2);
      int u3 = r[t1][1] ^ r[t2][1] ^ 1;
      if (u1 == u2 && u3 == 1) break;
      r[u1][0] = u2;
      r[u1][1] = u3;
    }
    if (i == 0)
      printf("-1\n");
    else
      printf("%d\n", in[i].first.first);
  }
  return 0;
}
