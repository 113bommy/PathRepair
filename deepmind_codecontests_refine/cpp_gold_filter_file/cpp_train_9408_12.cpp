#include <bits/stdc++.h>
using namespace std;
int n, m, a[200001], type[200001], C[200001][3], pos[200001];
bool cmp(const int &x, const int &y) {
  return (a[x] < a[y] || (a[x] == a[y] && type[x] < type[y]));
}
int main() {
  scanf("%d", &n);
  n += n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (i <= n / 2)
      type[i] = i;
    else
      type[i] = i - n / 2;
    pos[i] = i;
  }
  scanf("%d", &m);
  memset(C, 0, sizeof(C));
  C[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i && j <= 2; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % m;
  }
  sort(pos + 1, pos + n + 1, cmp);
  long long ans = 1;
  for (int i = 1; i <= n; i++)
    if (i == 1 || a[pos[i]] != a[pos[i - 1]]) {
      int cnt = 0;
      for (int j = i; j <= n; j++)
        if (a[pos[j]] == a[pos[i]])
          ++cnt;
        else
          break;
      int now = 1;
      for (int j = i + 1; j <= n; j++)
        if (a[pos[j]] == a[pos[i]]) {
          if (type[pos[j]] == type[pos[j - 1]])
            ++now;
          else
            ans *= C[cnt][now], ans %= m, cnt -= now, now = 1;
        } else
          break;
    }
  printf("%I64d\n", ans);
}
