#include <bits/stdc++.h>
using namespace std;
int n, m, k, hd[500005], bg[500005], lg[500005], b2[25], st[500005][21],
    ed[500005];
unsigned long long bin[500005], b17[500005], hs[500005], HS[500005], ht[500005],
    HT[500005];
char s[500005], t[500005];
void gethash() {
  for (int i = 1; i <= n; i++)
    hs[i] = hs[i - 1] * 26 + s[i] - 'a', HS[i] = HS[i - 1] * 17 + s[i] - 'a';
  for (int i = 1; i <= m; i++)
    ht[i] = ht[i - 1] * 26 + t[i] - 'a', HT[i] = HT[i - 1] * 17 + t[i] - 'a';
}
unsigned long long get(int l, int r, unsigned long long *x) {
  return x[r] - x[l - 1] * bin[r - l + 1];
}
unsigned long long GET(int l, int r, unsigned long long *x) {
  return x[r] - x[l - 1] * b17[r - l + 1];
}
void getmatch(int *x) {
  int l, r, ans, mid;
  for (int i = 1; i <= n; i++) {
    l = ans = 0;
    r = min(min(m, n - i + 1), k);
    while (l <= r) {
      mid = (l + r) >> 1;
      if (get(i, i + mid - 1, hs) == get(1, 1 + mid - 1, ht) &&
          GET(i, i + mid - 1, HS) == GET(1, 1 + mid - 1, HT))
        l = (ans = mid) + 1;
      else
        r = mid - 1;
    }
    x[i] = ans;
  }
}
int Max(int x, int y) { return ed[x] > ed[y] ? x : y; }
int ask(int x, int y) {
  int t = lg[y - x + 1];
  return Max(st[x][t], st[y - b2[t] + 1][t]);
}
void predeal() {
  bin[0] = b2[0] = b17[0] = 1;
  for (int i = 1; i <= n; i++) bin[i] = bin[i - 1] * 26;
  for (int i = 1; i <= n; i++) b17[i] = b17[i - 1] * 17;
  gethash();
  getmatch(bg);
  reverse(s + 1, s + 1 + n);
  reverse(t + 1, t + 1 + m);
  gethash();
  getmatch(ed);
  reverse(ed + 1, ed + 1 + n);
  for (int i = 1; i <= n; i++) st[i][0] = i;
  for (int i = 1; i <= 20; i++) b2[i] = b2[i - 1] << 1;
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  for (int j = 1; b2[j] <= n; j++)
    for (int i = 1; i + b2[j - 1] <= n; i++)
      st[i][j] = Max(st[i][j - 1], st[i + b2[j - 1]][j - 1]);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  scanf("%s%s", s + 1, t + 1);
  predeal();
  int x, y, len;
  for (int i = 1; i <= n; i++)
    if (bg[i] == m) {
      puts("Yes");
      int mid = n >> 1, a1, a2;
      if (i > mid)
        printf("%d %d", a1 = 1, a2 = i + k <= n ? i + k : n - k + 1);
      else if (i + m <= mid)
        printf("%d %d", a1 = i + m - k >= 1 ? i + m - k : 1, a2 = mid + 1);
      else
        printf("%d %d", a1 = mid - k + 1, a2 = mid + 1);
      return 0;
    }
  for (int i = 1; i <= n; i++) {
    x = bg[i];
    if (i <= k - x) continue;
    if (i + x + k - 1 > n) continue;
    if (i + m > n) break;
    y = ask(i + m - 1, n - k + m - x);
    len = min(ed[y], m - x);
    if (y - len + k > n) continue;
    if (len + x == m) {
      puts("Yes");
      printf("%d %d", i + x - k, y - len + 1);
      return 0;
    }
  }
  puts("No");
  return 0;
}
