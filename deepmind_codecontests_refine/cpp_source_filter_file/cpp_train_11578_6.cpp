#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
const int MAXN = 200010;
int Sum[MAXN], a[MAXN];
int M, N, K, T;
struct Node {
  int l, r, d;
} p[MAXN];
inline bool check(int d) {
  memset(Sum, 0, sizeof(Sum));
  for (int i = 1; i <= M; ++i)
    if (p[i].d > d) {
      ++Sum[p[i].l];
      --Sum[p[i].r];
    }
  int Ret = N + 1;
  for (int i = 1; i <= N; ++i) {
    Sum[i] += Sum[i - 1];
    if (Sum[i]) Ret += 2;
  }
  if (Ret <= T) return true;
  return false;
}
int main() {
  M = read();
  N = read();
  K = read();
  T = read();
  for (int i = 1; i <= M; ++i) a[i] = read();
  for (int i = 1; i <= K; ++i) {
    p[i].l = read();
    p[i].r = read();
    p[i].d = read();
  }
  sort(a + 1, a + N + 1, greater<int>{});
  int L = 1, R = N;
  if (!check(a[1])) {
    printf("0\n");
    return 0;
  }
  if (check(a[N])) {
    printf("%d\n", N);
    return 0;
  }
  while (L + 1 < R) {
    int mid = (L + R) >> 1;
    if (check(a[mid]))
      L = mid;
    else
      R = mid;
  }
  printf("%d\n", L);
  return 0;
}
