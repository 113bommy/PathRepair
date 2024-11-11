#include <bits/stdc++.h>
using namespace std;
const int BSIZE = 400;
const int MAXM = 100005;
const int MAXN = 100005;
const int BLOCKS = MAXN / BSIZE + 5;
const int MAXV = MAXN + MAXM;
pair<int, pair<int, int> > queries[MAXM];
int A[MAXN], discreteInv[MAXV], N, n, M, X[BLOCKS][MAXV], cnt[MAXV];
short Y[BLOCKS][MAXN];
int solve(int r, int c) {
  if (!r) return discreteInv[A[c]];
  int b = c / BSIZE;
  int x = X[b][A[c]], y = 0;
  for (int i = b * BSIZE; i <= c; ++i) x += A[i] == A[c];
  if (r & 1) return x;
  for (int i = 0; i < b; ++i) y += Y[i][x];
  for (int i = b * BSIZE; i <= c; ++i) {
    if (cnt[A[i]] == -1) cnt[A[i]] = X[b][A[i]];
    ++cnt[A[i]];
    y += cnt[A[i]] == x;
  }
  for (int i = b * BSIZE; i <= c; ++i) cnt[A[i]] = -1;
  return y;
}
int main() {
  map<int, int> discrete;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A[i]);
    discrete[A[i]] = 1;
  }
  scanf("%d", &M);
  for (int i = 0; i < M; ++i) {
    scanf("%d%d%d", &queries[i].first, &queries[i].second.first,
          &queries[i].second.second);
    if (queries[i].first == 1) {
      discrete[queries[i].second.first] = 1;
    }
  }
  for (auto i = discrete.begin(); i != discrete.end(); ++i) {
    discreteInv[++n] = i->second;
    i->second = n;
  }
  int lastBlock = (N - 1) / BSIZE;
  for (int i = 0; i < N; ++i) {
    A[i] = discrete[A[i]];
    int b = i / BSIZE;
    ++cnt[A[i]];
    for (int j = b + 1; j <= lastBlock; ++j) X[j][A[i]] = cnt[A[i]];
    ++Y[b][cnt[A[i]]];
  }
  memset(cnt, -1, sizeof(cnt));
  for (int i = 0; i < M; ++i) {
    if (queries[i].first == 1) {
      int v = discrete[queries[i].second.first],
          c = queries[i].second.second - 1;
      int p = A[c];
      if (v == p) continue;
      int b = c / BSIZE;
      for (int j = b; j + 1 <= lastBlock; ++j) {
        --Y[j][X[j + 1][p]];
        if (j != b) ++Y[j][X[j][p]];
        ++Y[j][X[j + 1][v] + 1];
        if (j != b) --Y[j][X[j][v] + 1];
      }
      for (int j = b + 1; j <= lastBlock; ++j) {
        --X[j][p];
        ++X[j][v];
      }
      A[c] = v;
    } else {
      printf("%d\n",
             solve(queries[i].second.first - 1, queries[i].second.second - 1));
    }
  }
}
