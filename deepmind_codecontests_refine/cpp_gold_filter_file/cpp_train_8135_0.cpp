#include <bits/stdc++.h>
const int N = 200233;
const int maxn = N * 25;
int num, n, cnt1, cnt2;
int p[N * 25], minp[N * 25], a[N * 3], b[N * 3];
bool book[N * 25];
std ::map<int, int> s;
int min(int a, int b) { return a < b ? a : b; }
void prime() {
  memset(book, true, sizeof(book));
  book[0] = book[1] = false;
  for (int i = 2; i <= maxn; ++i) {
    if (book[i]) {
      p[++num] = i;
      minp[i] = i;
    }
    for (int j = 1; j <= num && p[j] * i <= maxn; ++j) {
      book[i * p[j]] = false;
      minp[i * p[j]] = min(minp[i], p[j]);
      if (i % p[j] == 0) break;
    }
  }
}
int main(void) {
  prime();
  scanf("%d", &n);
  for (int i = 1; i <= 2 * n; ++i) {
    int x;
    scanf("%d", &x);
    if (book[x])
      a[++cnt1] = x;
    else
      b[++cnt2] = x;
  }
  std ::sort(a + 1, a + 1 + cnt1);
  std ::sort(b + 1, b + 1 + cnt2);
  for (int i = cnt2; i >= 1; --i) {
    if (s[b[i]]) {
      s[b[i]]--;
      continue;
    }
    printf("%d ", b[i]);
    s[b[i] / minp[b[i]]]++;
  }
  for (int i = 1; i <= cnt1; ++i) {
    if (s[a[i]]) {
      s[a[i]]--;
      continue;
    }
    printf("%d ", a[i]);
    s[p[a[i]]]++;
  }
  return 0;
}
