#include <bits/stdc++.h>
using namespace std;
const int Max_N = 2e5;
int n, k, Aver, Ans, Ed, tot, a[Max_N + 5], p[Max_N + 5], lst[Max_N + 5],
    fir[Max_N + 5], ans[Max_N + 5];
int w[Max_N + 5];
map<int, int> pos[Max_N + 5];
vector<int> s[Max_N + 5];
inline int Sum(int l, int r) {
  int sum = 0;
  for (int i = l; i <= r; i++) sum += a[i];
  return sum;
}
inline void Solv(int l, int r) {
  if (l == r) return;
  int now = min(l + k - 1, r), sum = Sum(l, min(l + k - 1, r)), lst = l;
  for (; now < r && sum < (now - l + 1) * Aver;
       sum += Sum(now + 1, min(now + k - 1, r)), lst = now,
                                                 now = min(r, now + k - 1))
    ;
  int Oth = sum - (now - l + 1) * Aver;
  int summ = Sum(lst, now) - (now - lst + 1) * Aver - Oth;
  ++tot;
  s[tot].push_back(lst % n);
  s[tot].push_back(Aver + summ), a[lst % n] = a[lst % n + n] = Aver + summ;
  for (int i = lst + 1; i < now; i++)
    s[tot].push_back(Aver), a[i % n] = a[i % n + n] = Aver;
  s[tot].push_back(Aver + Oth), a[now % n] = a[now % n + n] = Aver + Oth;
  for (int i = now + 1; i <= l + k - 1; i++) s[tot].push_back(a[i % n]);
  for (int i = lst - (k - 1); i >= l; i -= k - 1) {
    int nr = i + k - 1;
    summ = Sum(i, nr) - k * Aver;
    ++tot;
    s[tot].push_back(i % n);
    s[tot].push_back(summ + Aver), a[i % n] = a[i % n + n] = summ + Aver;
    for (int j = i + 1; j <= nr; j++)
      s[tot].push_back(Aver), a[j % n] = a[j % n + n] = Aver;
  }
  if (now < r) Solv(now, r);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  p[0] = a[0];
  for (int i = 1; i < n; i++) p[i] = p[i - 1] + a[i];
  Aver = p[n - 1] / n;
  for (int i = 0; i < n; i++) p[i] -= (i + 1) * Aver;
  for (int i = 0; i < n; i++) {
    lst[i] = pos[(i - 1 + k - 1) % (k - 1)][p[i]] - 1,
    pos[i % (k - 1)][p[i]] = i + 1;
    if (lst[i] == -1)
      fir[i] = i, ans[i] = 0;
    else
      fir[i] = fir[lst[i]],
      ans[i] = ans[lst[i]] + (i - lst[i] - 1 + k - 2) / (k - 1);
  }
  Ans = n + 1;
  for (int i = 0; i < n; i++)
    if (pos[i % (k - 1)][p[i]] == i + 1) {
      int val = ans[i] + (fir[i] - i + n - 1 + k - 2) / (k - 1);
      if (val < Ans) Ed = i, Ans = val;
    }
  for (int i = 0; i < n; i++) a[i + n] = a[i];
  printf("%d\n", Ans);
  for (int x = Ed; lst[x] != -1; x = lst[x]) Solv(lst[x] + 1, x);
  Solv(Ed + 1, fir[Ed] + n);
  for (int i = 1; i <= tot; i++) {
    for (int j = 0; j < s[i].size(); j++) printf("%d ", s[i][j]);
    puts("");
  }
  return 0;
}
