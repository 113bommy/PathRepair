#include <bits/stdc++.h>
using namespace std;
const int nmax = 200005;
int n, a[nmax];
long long sum[nmax];
long double sol;
pair<int, int> A, B;
int C;
long long s(int i, int j) { return sum[j] - sum[i - 1]; }
long double f(int cnt, int i, int j, int sum) {
  return 1.0 * (1LL * sum + s(i - cnt + 1, i) + s(n - cnt + 1, n)) /
         (2 * cnt + j - i - 1);
}
pair<long double, int> solve(int i, int j, int sum) {
  int l = 1;
  int r = min(i, n - j + 1);
  int L = l;
  int R = r;
  if (l == r) return make_pair(f(l, i, j, sum), l);
  int where = -1;
  while (l <= r) {
    if (l == r) {
      where = l;
      break;
    }
    int mi = (l + r) / 2;
    if (f(mi, i, j, sum) > f(mi + 1, i, j, sum)) {
      r = mi - 1;
      where = mi;
    } else
      l = mi + 1;
  }
  long double muie = 0.0;
  int pl = -1;
  for (int I = max(L, where - 2); I <= min(R, where + 2); I++)
    if (f(I, i, j, sum) > muie) {
      muie = f(I, i, j, sum);
      pl = I;
    }
  return make_pair(f(pl, i, j, sum), pl);
}
int main() {
  cin.sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  for (int i = 2; i < n; i++) {
    pair<long double, int> mlc = solve(i - 1, i + 1, a[i]);
    long double best_mean = mlc.first;
    int cnt = mlc.second;
    if (best_mean - 1.0 * a[i] > sol) {
      sol = best_mean - 1.0 * a[i];
      A = make_pair(i - cnt, i - 1);
      B = make_pair(n - cnt + 1, n);
      C = 1;
    }
  }
  for (int i = 2; i < n - 1; i++) {
    pair<long double, int> mlc = solve(i - 1, i + 2, a[i] + a[i + 1]);
    long double best_mean = mlc.first;
    int cnt = mlc.second;
    if (best_mean - 1.0 * (a[i] + a[i + 1]) / 2.0 > sol) {
      sol = best_mean - 1.0 * (a[i] + a[i + 1]) / 2.0;
      A = make_pair(i - cnt, i - 1);
      B = make_pair(n - cnt + 1, n);
      C = 2;
    }
  }
  if (A.second == 0) {
    printf("1\n");
    printf("%d", a[1]);
    return 0;
  }
  printf("%d\n", A.second - A.first + 1 + B.second - B.first + 1 + C);
  for (int i = A.first; i <= A.second; i++) printf("%d ", a[i]);
  for (int i = B.first; i <= B.second; i++) printf("%d ", a[i]);
  printf("%d", a[A.second + 1]);
  if (C == 2) printf("%d", a[A.second + 2]);
  return 0;
}
