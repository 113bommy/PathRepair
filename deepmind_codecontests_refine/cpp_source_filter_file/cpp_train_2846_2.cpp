#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int N, M, C;
int a[MAXN];
int b[MAXN];
long long ps[MAXN];
int l[MAXN], r[MAXN];
int main(int argc, char *argv[]) {
  scanf("%d%d%d", &N, &M, &C);
  for (int i = 0, _i = N; i < _i; ++i) {
    scanf("%d", a + i + 1);
  }
  for (int i = 0, _i = M; i < _i; ++i) {
    scanf("%d", b + i + 1);
    ps[i + 1] = ps[i] + b[i + 1];
  }
  for (int i = (1), _i = (N); i <= _i; ++i) {
    if (i <= M) {
      r[i] = i;
      if (N - M + 1 >= i) {
        l[i] = 1;
      } else {
        l[i] = i - (N - M);
      }
    } else if (i >= N - M + 1) {
      r[i] = M;
      l[i] = N - i + 1;
    } else {
      l[i] = 1;
      r[i] = M;
    }
  }
  for (int i = (1), _i = (N); i <= _i; ++i) {
    printf("%d ", (a[i] + ((ps[r[i]] - ps[l[i] - 1]) % (long long)C)) % C);
  }
  return 0;
}
