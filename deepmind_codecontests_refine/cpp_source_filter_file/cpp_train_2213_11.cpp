#include <bits/stdc++.h>
using namespace std;
int n, m;
long long x, k, y;
int A[100003], B[100003];
bool bol = 1;
long long solve(vector<int> &vec, int mx) {
  int sz = vec.size();
  bool big = 0;
  for (int x : vec) big |= (x > mx);
  if (!vec.size()) return 0;
  if (vec.size() < k && big) {
    bol = 0;
    return 0;
  } else if (sz < k && !big)
    return y * sz;
  else if (sz >= k && big) {
    return y * (sz % k) + x + min((sz / k - 1) * x, (sz - sz % k - k) * y);
  } else
    return y * (sz % k) + min((sz / k) * x, (sz - sz % k) * y);
}
int main() {
  scanf("%d %d", &n, &m);
  scanf("%lld %lld %lld", &x, &k, &y);
  for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &B[i]);
  int mx = 0, j = 1;
  long long res = 0;
  vector<int> vec;
  for (int i = 1; i <= n; i++) {
    if (A[i] == B[j]) {
      mx = max(mx, B[j]);
      j++;
      res += solve(vec, mx);
      mx = A[i];
      vec.clear();
    } else {
      vec.push_back(A[i]);
    }
  }
  res += solve(vec, mx);
  if (j != n + 1) bol = 0;
  printf("%lld\n", (bol) ? res : -1);
}
