#include <bits/stdc++.h>
template <class T>
__inline__ __attribute__((always_inline)) long long chkmax(T &a,
                                                           const long long b) {
  if (a < b) a = b;
  return a;
}
template <class T>
__inline__ __attribute__((always_inline)) long long chkmin(T &a,
                                                           const long long b) {
  if (a > b) a = b;
  return a;
}
__inline__ __attribute__((always_inline)) long long mymax(const long long a,
                                                          const long long b) {
  return a > b ? a : b;
}
__inline__ __attribute__((always_inline)) long long mymin(const long long a,
                                                          const long long b) {
  return a < b ? a : b;
}
__inline__ __attribute__((always_inline)) long long myabs(const long long &a) {
  return a > 0 ? a : -a;
}
const int INF = 0X3F3F3F3F;
const double EPS = 1E-10, PI = acos(-1.0);
const int MAXN = 200000 + 5;
int a[MAXN], right[MAXN], stk[MAXN], zero[MAXN], sho[MAXN];
bool del[MAXN];
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  int cnt = 0;
  for (int i = 1, iend = n; i <= iend; ++i) {
    scanf("%d", &a[i]);
    if (!a[i]) zero[++cnt] = i;
    chkmax(right[a[i]], i);
  }
  if (!cnt && !right[q]) {
    puts("NO");
    exit(0);
  }
  int top = 0;
  for (int i = 1, iend = n; i <= iend; ++i) {
    while (top && del[top]) --top;
    if (!a[i]) {
      sho[i] = stk[top];
      continue;
    }
    if (a[i] < stk[top]) {
      puts("NO");
      exit(0);
    } else if (a[i] > stk[top])
      stk[++top] = a[i];
    if (right[a[i]] == i) del[a[i]] = 1;
  }
  puts("YES");
  if (!right[q]) a[zero[cnt]] = q;
  for (int i = 1, iend = cnt - !right[q]; i <= iend; ++i)
    a[zero[i]] = mymax(1, sho[zero[i]]);
  for (int i = 1, iend = n; i <= iend; ++i) printf("%d ", a[i]);
  puts("");
  return 0;
}
