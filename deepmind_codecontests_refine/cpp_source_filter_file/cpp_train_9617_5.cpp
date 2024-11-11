#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
const int MAXN = 2e5 + 5;
const int K = 2e5;
const int inf = 1e9 + 7;
int N;
long long kd[MAXN * 4];
long long lazy[MAXN * 4];
long long upd(int k, int b, int e, int x1, int x2, long long v) {
  if (b > x2 || e < x1) return kd[k] + lazy[k] * (e - b + 1);
  if (b >= x1 && e <= x2) {
    lazy[k] += v;
    return kd[k] + lazy[k] * (e - b + 1);
  }
  kd[k] = upd(k * 2, b, (b + e) / 2, x1, x2, v) +
          upd(k * 2 + 1, (b + e) / 2 + 1, e, x1, x2, v);
  return kd[k] + lazy[k] * (e - b + 1);
}
long long find(int k, int b, int e, int x1, int x2) {
  if (b > x2 || e < x1) return 0;
  if (b >= x1 && e <= x2) return kd[k] + lazy[k] * (e - b + 1);
  long long len = min(x2, e) - max(x1, b) + 1;
  return find(k * 2, b, (b + e) / 2, x1, x2) +
         find(k * 2 + 1, (b + e) / 2 + 1, e, x1, x2) + lazy[k] * len;
}
int main() {
  int T;
  cin >> T;
  N = 1;
  for (int(i) = (1); i <= (T); (i)++) {
    int t;
    scanf(" %d", &t);
    if (t == 1) {
      int x, a;
      scanf(" %d %d", &a, &x);
      upd(1, 1, K, 1, a, x);
    }
    if (t == 2) {
      int a;
      scanf(" %d", &a);
      ++N;
      upd(1, 1, K, N, N, a);
    }
    if (t == 3) {
      upd(1, 1, K, N, N, -find(1, 1, K, N, N));
      --N;
    }
    printf("%.10lf\n", (double)find(1, 1, K, 1, K) / N);
  }
  return 0;
}
