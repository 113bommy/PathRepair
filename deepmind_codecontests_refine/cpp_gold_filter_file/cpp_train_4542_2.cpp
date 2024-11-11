#include <bits/stdc++.h>
using namespace std;
template <typename T>
T Abs(T first) {
  return (first < 0 ? -first : first);
}
template <typename T>
T Sqr(T first) {
  return (first * first);
}
string plural(string s) {
  return (int((s).size()) && s[int((s).size()) - 1] == 'x' ? s + "en"
                                                           : s + "s");
}
const int INF = (int)1e9;
const long double EPS = 1e-12;
const long double PI = acos(-1.0);
bool Read(int &first) {
  char c, r = 0, n = 0;
  first = 0;
  for (;;) {
    c = getchar();
    if ((c < 0) && (!r)) return (0);
    if ((c == '-') && (!r))
      n = 1;
    else if ((c >= '0') && (c <= '9'))
      first = first * 10 + c - '0', r = 1;
    else if (r)
      break;
  }
  if (n) first = -first;
  return (1);
}
int S, K;
int cc, O[50], cnt[50], req[50];
vector<int> con[50];
int dist[50][50], ind[50], dyn[51][51], dyn2[51][51];
void rec(int i, int p) {
  cc += cnt[i];
  if (ind[i] == 1) O[K++] = i;
  int j, k;
  for (j = 0; j < int((con[i]).size()); j++)
    if ((k = con[i][j]) != p) rec(k, i);
  if (p == S) req[K] = cc;
}
int main() {
  if (0) freopen("in.txt", "r", stdin);
  int N, M;
  int i, j, k;
  int a, b, c, r;
  memset(dist, 60, sizeof(dist));
  Read(N);
  for (i = 0; i < N - 1; i++) {
    Read(a), Read(b), Read(c);
    a--, b--;
    con[a].push_back(b);
    con[b].push_back(a);
    ind[a]++;
    ind[b]++;
    dist[a][b] = dist[b][a] = c;
  }
  Read(S), Read(M), S--;
  for (i = 0; i < M; i++) Read(j), j--, cnt[j]++;
  for (i = 0; i < N; i++) dist[i][i] = 0;
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      for (k = 0; k < N; k++)
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
  memset(req, -1, sizeof(req));
  rec(S, -1);
  memset(dyn[0], 0, sizeof(dyn[0]));
  for (a = 1; a <= M - 1; a++)
    for (b = 0; b < K; b++) {
      r = O[b];
      memset(dyn2, 0, sizeof(dyn2));
      dyn2[0][0] = INF;
      for (i = 0; i < K; i++)
        for (j = 0; j < a + 1; j++) {
          dyn2[i + 1][j] = max(dyn2[i + 1][j], dyn2[i][j]);
          if (O[i] != r)
            for (k = j + 1; k <= a; k++)
              dyn2[i + 1][k] =
                  max(dyn2[i + 1][k],
                      min(dyn2[i][j], dist[r][O[i]] + dyn[a - (k - j)][i]));
        }
      dyn[a][b] = dyn2[K][a];
    }
  a = M;
  r = S;
  memset(dyn2, 0, sizeof(dyn2));
  dyn2[0][0] = INF;
  for (i = 0; i < K; i++) {
    if (req[i] >= 0)
      for (j = 0; j < a + 1; j++)
        if (j != req[i]) dyn2[i][j] = 0;
    for (j = 0; j < a + 1; j++) {
      dyn2[i + 1][j] = max(dyn2[i + 1][j], dyn2[i][j]);
      if (O[i] != r)
        for (k = j + 1; k <= a; k++)
          dyn2[i + 1][k] =
              max(dyn2[i + 1][k],
                  min(dyn2[i][j], dist[r][O[i]] + dyn[a - (k - j)][i]));
    }
  }
  printf("%d\n", dyn2[K][a]);
  return (0);
}
