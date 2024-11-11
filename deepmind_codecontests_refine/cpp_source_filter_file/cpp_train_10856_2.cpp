#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N], cnt[N], tot, c[N];
set<int> S;
pair<int, int> st[N];
bool check() {
  int w = 0;
  for (int i = 1; i <= 2 * n; i++)
    if (cnt[i] == cnt[i - 1]) {
      if (*S.begin() == c[++w])
        S.erase(S.begin());
      else
        return false;
    } else
      S.insert(a[cnt[i]]);
  return 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 2 * n; i++) {
    char o[10];
    int x;
    scanf("%s", o + 1);
    cnt[i] = cnt[i - 1];
    if (o[1] == '+') {
      cnt[i]++;
    } else {
      scanf("%d", &x);
      st[++tot] = make_pair(x, cnt[i]);
      c[tot] = x;
    }
  }
  sort(st + 1, st + tot + 1);
  for (int i = 1; i <= n; i++) S.insert(i);
  for (int i = 1; i <= n; i++) {
    int p = st[i].second, v = st[i].first;
    set<int>::iterator it = S.upper_bound(p);
    if (it == S.begin()) return printf("No"), 0;
    it--;
    a[*it] = v;
    S.erase(it);
  }
  if (check() == 0) return printf("No"), 0;
  puts("Yes");
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  return 0;
}
