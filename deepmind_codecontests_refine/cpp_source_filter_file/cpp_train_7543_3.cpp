#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int L, R, A[N], B[N], n, m, s, Ans;
long long Res;
void failed() {
  puts("0");
  exit(0);
}
void cheat() {
  for (int i = 1; i <= m; i++)
    if (B[i] != B[m - i + 1]) return;
  printf("%I64d\n", 1ll * m * (m + 1) / 2);
  exit(0);
}
void init() {
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d", &B[i]);
  cheat();
  while (B[s + 1] == B[m - s] && s < m / 2) s++;
  for (int i = s + 1; i <= m - s; i++) A[++n] = B[i];
  memset(B, 0, sizeof B);
  return;
}
bool checkrest(int L, int R) {
  for (; L <= R; L++, R--)
    if (A[L] != A[R]) return 0;
  return 1;
}
bool check(int x) {
  memset(B, 0, sizeof B);
  for (int i = 1; i <= x; i++) B[A[i]]++;
  L = 1, R = n;
  if (x <= n / 2) {
    for (int i = R; i >= n - x + 1; i--)
      if (B[A[i]] == 0)
        return 0;
      else
        B[A[i]]--;
    return checkrest(x + 1, n - x);
  } else {
    int cnt = 0;
    for (int i = R; i >= x + 1; i--)
      if (B[A[i]] == 0)
        return 0;
      else
        B[A[i]]--;
    for (int i = 1; i < N; i++)
      if (B[i] % 2 == 1) cnt++;
    if (n % 2 == 0 && cnt) return 0;
    if (n % 2 == 1 && cnt > 1) return 0;
    return 1;
  }
  return puts("F@Q"), 233;
}
void solve() {
  Ans = 0;
  for (int l = 1, r = n; l <= r;) {
    int mid = l + r >> 1;
    if (check(mid))
      Ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  return;
}
int main() {
  init();
  solve();
  if (Ans) Res += 1ll * (s + 1) * (m - (s + Ans) + 1);
  for (int i = 1; i <= n / 2; i++) swap(A[i], A[n - i + 1]);
  solve();
  if (Ans) Res += 1ll * (s + 1) * (m - (s + Ans) + 1);
  if (!Res)
    puts("0");
  else
    printf("%I64d\n", Res - 1ll * (L + 1) * (L + 1));
  return 0;
}
