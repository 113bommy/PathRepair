#include <bits/stdc++.h>
using namespace std;
static inline void amin(int &a, int b) {
  if (a > b) a = b;
}
int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  int A[N];
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A[i]);
  }
  pair<int, int> Q[M];
  for (int i = 0; i < M; ++i) {
    scanf("%d%d", &Q[i].first, &Q[i].second);
    Q[i].first--;
    Q[i].second--;
  }
  int res = *max_element(A, A + N) - *min_element(A, A + N);
  list<int> res_q;
  int changes[N];
  for (int mx = 0; mx < N; ++mx) {
    list<int> q;
    memset(changes, 0, sizeof changes);
    for (int i = 0; i < M; ++i)
      if (mx < Q[i].first || Q[i].second < mx) {
        q.push_back(i);
        for (int j = Q[i].first; j < Q[i].second; ++j) changes[j]--;
      }
    int mn = numeric_limits<int>::max();
    for (int i = 0; i < N; ++i) amin(mn, A[i] + changes[i]);
    if (res < A[mx] - mn) {
      res = A[mx] - mn;
      res_q = q;
    }
  }
  printf("%d\n%d\n", res, (int)res_q.size());
  for (auto it : res_q) printf("%d ", it + 1);
  printf("\n");
  return 0;
}
