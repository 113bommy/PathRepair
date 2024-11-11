#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:65000000")
using namespace std;
template <typename T>
T mabs(const T &a) {
  return a < 0 ? -a : a;
}
const double PI = acos(-1.0);
const int mod = 1e9;
void run() {
  int n, m;
  cin >> n >> m;
  int A[200];
  for (int i = (0), ei = (n); i < ei; i++) scanf("%d", A + i);
  long long F[200] = {1, 1};
  for (int i = (2), ei = (200); i < ei; i++) F[i] = (F[i - 1] + F[i - 2]) % mod;
  for (int i = (0), ei = (m); i < ei; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x, v;
      scanf("%d%d", &x, &v);
      --x;
      A[x] = v;
    } else if (t == 2) {
      int l, r;
      scanf("%d%d", &l, &r);
      --l;
      --r;
      int res = 0;
      for (int j = (0), ej = (r - l + 1); j < ej; j++)
        res = (res + A[l + j] * F[j]) % mod;
      printf("%d\n", res);
    }
  }
}
int main() {
  run();
  return 0;
}
