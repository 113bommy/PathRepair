#include <bits/stdc++.h>
int D[100005], cnt[100005];
int N, M, st = 1, en = N;
bool chk(int l, int r) {
  for (int i = 1; i <= N; i++) cnt[i] = 0;
  for (int i = st; i <= en; i++) {
    if (l <= i && i <= r)
      cnt[D[i]]++;
    else if (l <= N - i + 1 && N - i + 1 <= r)
      cnt[D[i]]--;
    else if (D[N - i + 1] != D[i])
      return false;
  }
  int odd = 0;
  for (int i = 1; i <= N; i++) {
    if (cnt[i] < 0)
      return false;
    else if (cnt[i] & 1)
      odd++;
  }
  if (odd > N % 2) return false;
  return true;
}
int main() {
  scanf("%d", &N);
  st = 1, en = N;
  for (int i = 1; i <= N; i++) scanf("%d", D + i);
  while (st <= en) {
    if (D[st] == D[en])
      st++, en--;
    else
      break;
  }
  if (st > en) return !printf("%lld", (long long)N * (N - 1));
  if (!chk(1, N)) return !printf("0");
  M = en - st + 1;
  int s = 0, e = en - st, m, pre = en - st, suf = en - st;
  while (s <= e) {
    m = (s + e) / 2;
    if (chk(st, st + m))
      pre = m, e = m - 1;
    else
      s = m + 1;
  }
  s = 0, e = en - st;
  while (s <= e) {
    m = (s + e) / 2;
    if (chk(en - m, en))
      suf = m, e = m - 1;
    else
      s = m + 1;
  }
  int dif = (N - M) / 2 + 1;
  printf("%lld", (long long)dif * (N + M - dif - pre - suf));
}
