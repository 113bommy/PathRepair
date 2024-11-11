#include <bits/stdc++.h>
using namespace std;
const int MN = 1002;
int N, T;
vector<vector<int> > D;
vector<int> dsum, psum;
void get_dsum() {
  dsum.resize(T);
  for (int i = 0; i < T; i++) {
    dsum[i] = 0;
    for (int j = 0; j < D[i].size(); j++) {
      dsum[i] += D[i][j];
    }
  }
}
void get_psum() {
  psum.resize(T);
  for (int i = T; i--;) {
    psum[i] = dsum[i];
    if (i != T - 1) psum[i] += psum[i + 1];
  }
}
vector<vector<int> > cache;
int dp(int dep, int rem) {
  if (dep == T) return 0;
  if (rem > MN) return psum[dep];
  int& ret = cache[dep][rem];
  if (ret != -1) return ret;
  int sum = 0;
  ret = dp(dep + 1, 2 * rem);
  for (int i = 0; i < D[dep].size(); i++) {
    if (i + 1 > rem) break;
    sum += D[dep][i];
    ret = max(ret, sum + dp(dep + 1, 2 * (rem - i - 1)));
  }
  return ret;
}
int main() {
  scanf("%d %d", &N, &T);
  D.resize(T);
  for (int i = 0; i < N; i++) {
    int t, q;
    scanf("%d %d", &t, &q);
    t = T - t;
    D[t].push_back(q);
  }
  for (int i = 0; i < T; i++) {
    sort(D[i].begin(), D[i].end());
    reverse(D[i].begin(), D[i].end());
  }
  get_dsum();
  get_psum();
  cache = vector<vector<int> >(T, vector<int>(MN, -1));
  printf("%d", dp(0, 1));
}
