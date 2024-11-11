#include <bits/stdc++.h>
using namespace std;
long long Ans;
int n;
int A[300005], T[300005];
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline int count(long long x) {
  int res = 0;
  while (x) {
    ++res;
    x -= x & -x;
  }
  return res;
}
int main() {
  n = read();
  for (register int i = 1; i <= n; ++i)
    T[i] = T[i - 1] + (A[i] = count(read()));
  int cnt[2] = {0, 0};
  for (register int i = 1; i <= n; ++i) {
    int Max = A[i], sum = A[i];
    for (register int j = i - 1; j >= max(1, i - 65); --j) {
      Max = max(Max, A[j]);
      if (((T[i] - T[j - 1]) & 1) == 0 && Max + Max <= T[i] - T[j - 1]) ++Ans;
    }
    if (i > 64) ++cnt[T[i - 64] & 1];
    Ans += cnt[T[i] & 1];
  }
  printf("%lld\n", Ans);
  return 0;
}
