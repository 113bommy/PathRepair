#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chmax(T &a, T b) {
  a = max(a, b);
}
template <typename T>
void chmin(T &a, T b) {
  a = min(a, b);
}
template <typename T>
void chadd(T &a, T b) {
  a = a + b;
}
long long int dx[] = {0, 0, 1, -1};
long long int dy[] = {1, -1, 0, 0};
const long long INF = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;
const long long MOD = 1000000007LL;
vector<long long int> va, vb, A, B;
long long int N, K;
void make_array(vector<long long int> &ret, vector<long long int> &v,
                long long int cur = 1, long long int idx = 0,
                long long int flr = INF) {
  long long int M = v.size();
  if (idx == M)
    ret.push_back(cur);
  else {
    make_array(ret, v, cur, M, flr);
    for (long long int(k) = (idx); (k) < (M); (k)++) {
      long long int nxt = cur, tmp = flr;
      while (tmp / v[k]) {
        tmp /= v[k];
        nxt *= v[k];
        make_array(ret, v, nxt, k + 1, tmp);
      }
    }
  }
}
bool solve(long long int x) {
  long long int pa = 0, pb = 0;
  long long int X = A.size(), Y = B.size();
  long long int sum = 0;
  for (pa = X - 1; pa >= 0; pa--) {
    while (pb < Y && x / A[pa] / B[pb] > 0) pb++;
    sum += pb;
  }
  return sum < K;
}
signed main() {
  scanf("%lld", &N);
  for (long long int(i) = (0); (i) < (N); (i)++) {
    long long int val;
    scanf("%lld", &val);
    (i % 2 ? va : vb).push_back(val);
  }
  scanf("%lld", &K);
  make_array(A, va);
  make_array(B, vb);
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  long long int ub = INF + 1000, lb = 0;
  while (ub - lb > 1) {
    long long int mid = (ub + lb) / 2;
    if (solve(mid))
      lb = mid;
    else
      ub = mid;
  }
  printf("%lld\n", ub);
  return 0;
}
