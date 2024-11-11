#include <bits/stdc++.h>
using namespace std;
const int nmax = 2e5 + 42;
int n, arr[nmax];
pair<int, int> sparse[20][nmax];
int lg[nmax];
void build() {
  for (int i = 1; i <= n; i++) sparse[0][i] = {arr[i], i};
  for (int sz = 1; (1 << sz) <= n; sz++)
    for (int j = 1; j + (1 << sz) - 1 <= n; j++) {
      sparse[sz][j] =
          max(sparse[sz - 1][j], sparse[sz - 1][j + (1 << (sz - 1))]);
    }
  for (int j = 3; j <= n; j++) lg[j] = lg[j / 2] + 1;
}
pair<int, int> query(int l, int r) {
  if (l > r) swap(l, r);
  if (l == r) return {arr[l], l};
  int st = lg[r - l + 1];
  return max(sparse[st][l], sparse[st][r - (1 << st) + 1]);
}
int where[nmax];
long long solve(int l, int r) {
  if (r - l + 1 <= 2) return 0;
  int av = query(l, r).second;
  long long ret = solve(l, av - 1) + solve(av + 1, r);
  int lq, rq;
  int where_l, where_r;
  if (av <= (l + r) / 2) {
    lq = l;
    rq = av - 1;
    where_l = av + 1;
    where_r = r;
  } else {
    lq = av + 1;
    rq = r;
    where_l = l;
    where_r = av - 1;
  }
  for (int i = lq; i <= rq; i++) {
    int aim = arr[av] - arr[i];
    if (aim <= 0) continue;
    if (where_l <= where[aim] && where[aim] <= where_r &&
        query(i, where[aim]).second == av)
      ret++;
  }
  return ret;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= n; i++) where[arr[i]] = i;
  build();
  cout << solve(1, n) << endl;
  return 0;
}
