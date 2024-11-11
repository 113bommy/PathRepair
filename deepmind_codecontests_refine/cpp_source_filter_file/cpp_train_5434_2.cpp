#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
char s[maxn], ts[maxn];
int sum[maxn];
vector<int> v;
int main() {
  int n, mn = 1e9, pos, cnt = 0;
  scanf("%d%s", &n, s + 1);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + (s[i] == '(' ? 1 : -1);
    if (sum[i] < mn) mn = sum[i], pos = i;
  }
  if (sum[n]) {
    printf("0\n1 1\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) ts[i] = s[(i + pos - 1) % n + 1];
  for (int i = 1; i <= n; i++) s[i] = ts[i];
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + (s[i] == '(' ? 1 : -1);
    cnt += (!sum[i] ? 1 : 0);
  }
  v.push_back(0);
  for (int i = 1; i <= n; i++) {
    if (!sum[i]) v.push_back(i);
  }
  int ans = cnt, ansl = 1, ansr = 1;
  int siz = v.size();
  for (int i = 1; i < siz; i++) {
    int l = v[i - 1] + 1, r = v[i], tmp = 0;
    for (int j = l; j <= r; j++) tmp += (sum[j] == 1 ? 1 : 0);
    if (tmp > ans) ans = tmp, ansl = l, ansr = r;
  }
  v.clear();
  for (int i = 1; i <= n; i++) {
    if (sum[i] == 1) v.push_back(i);
  }
  siz = v.size();
  for (int i = 1; i < siz; i++) {
    int l = v[i - 1] + 1, r = v[i], tmp = 0;
    if (!sum[l]) continue;
    for (int j = l; j <= r; j++) tmp += (sum[j] == 2 ? 1 : 0);
    if (tmp > ans) ans = tmp, ansl = l, ansr = r;
  }
  printf("%d\n%d %d\n", ans, (ansl + pos - 1) % n + 1,
         (ansr + pos - 1) % n + 1);
  return 0;
}
