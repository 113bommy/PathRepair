#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int M = 300005;
char s[N][N], t[10];
int c[M], lx[M], ly[M];
int n, m, Q, rx[M], ry[M];
long long T[N][N], S[26][N][N];
int main() {
  scanf("%d%d%d", &n, &m, &Q);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%s", s[i] + 1);
  for (int i = (int)(1); i <= (int)(Q); i++) {
    scanf("%d%d%d%d%s", &lx[i], &ly[i], &rx[i], &ry[i], t + 1);
    c[i] = t[1] - 'a';
    ++S[t[1] - 'a'][lx[i]][ly[i]];
    --S[t[1] - 'a'][lx[i]][ry[i] + 1];
    --S[t[1] - 'a'][rx[i] + 1][ly[i]];
    ++S[t[1] - 'a'][rx[i] + 1][ry[i] + 1];
  }
  for (int i = (int)(0); i <= (int)(25); i++) {
    for (int j = (int)(1); j <= (int)(n); j++)
      for (int k = (int)(1); k <= (int)(m); k++) S[i][j][k] += S[i][j - 1][k];
    for (int j = (int)(1); j <= (int)(n); j++)
      for (int k = (int)(1); k <= (int)(m); k++) S[i][j][k] += S[i][j][k - 1];
  }
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(1); j <= (int)(m); j++) {
      int c = s[i][j] - 'a', SS = Q;
      for (int k = (int)(0); k <= (int)(25); k++) SS -= S[k][i][j];
      S[c][i][j] += SS;
      for (int k = (int)(0); k <= (int)(25); k++)
        T[i][j] += abs(c - k) * S[k][i][j];
    }
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(1); j <= (int)(m); j++) T[i][j] += T[i][j - 1];
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(1); j <= (int)(m); j++) T[i][j] += T[i - 1][j];
  for (int i = (int)(0); i <= (int)(25); i++) {
    for (int j = (int)(1); j <= (int)(n); j++)
      for (int k = (int)(1); k <= (int)(m); k++) S[i][j][k] += S[i][j - 1][k];
    for (int j = (int)(1); j <= (int)(n); j++)
      for (int k = (int)(1); k <= (int)(m); k++) S[i][j][k] += S[i][j][k - 1];
  }
  long long res = 1ll << 60;
  for (int i = (int)(1); i <= (int)(Q); i++) {
    long long ans = T[n][m];
    ans -= T[rx[i]][ry[i]];
    ans += T[lx[i] - 1][ry[i]];
    ans += T[rx[i]][ly[i] - 1];
    ans -= T[lx[i] - 1][ly[i] - 1];
    for (int j = (int)(0); j <= (int)(25); j++) {
      long long sum = 0;
      sum += S[j][rx[i]][ry[i]];
      sum -= S[j][lx[i] - 1][ry[i]];
      sum -= S[j][rx[i]][ly[i] - 1];
      sum += S[j][lx[i] - 1][ly[i] - 1];
      ans += abs(j - c[i]) * sum;
    }
    res = min(res, ans);
  }
  printf("%lld\n", res);
}
