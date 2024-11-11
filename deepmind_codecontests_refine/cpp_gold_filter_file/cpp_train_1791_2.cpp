#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, sum, ans, sl, sr, minn = 1e9, id;
char c[N], s[N];
int top, num, p[N], l[N], r[N], v[N], fa[N];
int main() {
  scanf("%d%s", &n, c + 1);
  for (int i = 1; i <= n; i++) {
    sum += c[i] == '(' ? 1 : -1;
    if (sum < minn) minn = sum, id = i;
  }
  if (sum) return printf("0\n1 1"), 0;
  for (int i = 1; i <= id; i++) s[n - id + i] = c[i];
  for (int i = id + 1; i <= n; i++) s[i - id] = c[i];
  for (int i = 1; i <= n; i++) {
    if (s[i] == '(')
      p[++top] = ++num, l[num] = i;
    else
      r[p[top]] = i, fa[p[top]] = p[top - 1], v[p[--top]]++;
  }
  ans = v[0];
  sl = sr = 1;
  for (int i = 1; i <= num; i++) {
    if (!fa[i] && v[i] + 1 > ans) ans = v[i] + 1, sl = l[i], sr = r[i];
    if (!fa[fa[i]] && fa[i] && v[i] + v[0] + 1 > ans)
      ans = v[i] + v[0] + 1, sl = l[i], sr = r[i];
  }
  sl += id;
  sl -= sl > n ? n : 0;
  sr += id;
  sr -= sr > n ? n : 0;
  printf("%d\n%d %d", ans, sl, sr);
}
