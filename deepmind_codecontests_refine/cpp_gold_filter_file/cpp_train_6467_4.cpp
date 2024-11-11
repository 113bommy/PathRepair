#include <bits/stdc++.h>
using namespace std;
int N;
const int M = 300000;
int64_t A[300000];
vector<int> edges[M];
int64_t ansv = 0, ansk = 0;
int64_t dfs(int i, int p) {
  int64_t sum = A[i];
  for (int j : edges[i])
    if (p != j) sum += dfs(j, i);
  ansv = max(ansv, sum);
  return max(sum, (int64_t)0);
}
int64_t dfs2(int i, int p) {
  int64_t sum = A[i];
  for (int j : edges[i])
    if (p != j) sum += dfs2(j, i);
  if (sum == ansv) {
    ansk++;
    return 0;
  } else {
    return max(sum, (int64_t)0);
  }
}
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edges[a - 1].push_back(b - 1);
    edges[b - 1].push_back(a - 1);
  }
  int64_t mx = *max_element(A, A + N);
  if (mx <= 0) {
    ansv = mx;
    ansk = count(A, A + N, mx);
  } else {
    dfs(0, -1);
    dfs2(0, -1);
  }
  cout << ansv * ansk << " " << ansk << endl;
  return 0;
}
