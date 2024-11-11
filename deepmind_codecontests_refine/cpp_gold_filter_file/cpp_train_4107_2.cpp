#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int N, M;
int A[MAXN];
vector<int> V[MAXN];
long long get_diff(int p, int x) {
  long long ret = 0;
  for (int i = 0; i < V[p].size(); ++i) {
    ret += abs(V[p][i] - x);
  }
  return ret;
}
int main(void) {
  scanf("%d%d", &M, &N);
  long long ans = 0;
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A[i]);
    if (i > 0) ans += abs(A[i] - A[i - 1]);
    if (i > 0 && A[i] != A[i - 1]) {
      V[A[i]].push_back(A[i - 1]);
      V[A[i - 1]].push_back(A[i]);
    }
  }
  long long mx = 0;
  for (int i = 1; i <= M; ++i) {
    if (V[i].size() == 0) continue;
    sort(V[i].begin(), V[i].end());
    long long init = get_diff(i, i);
    for (int j = -2; j <= 2; ++j) {
      int k = V[i].size() / 2 + j;
      if (k < 0) continue;
      if (k >= V[i].size()) break;
      long long diff = init - get_diff(i, V[i][k]);
      if (diff > mx) mx = diff;
    }
  }
  cout << ans - mx << endl;
  return 0;
}
