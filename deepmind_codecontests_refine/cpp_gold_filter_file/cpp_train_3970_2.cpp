#include <bits/stdc++.h>
const int MAXN = 1000;
int n;
char str[MAXN][MAXN];
char res[MAXN];
int len[MAXN];
int arr[MAXN];
bool visit1[MAXN], visit2[MAXN];
bool ok;
void dfs(int level) {
  if (level == n - 1) {
    for (int i = 0; i < n - 1; ++i) {
      int x = i * 2;
      if (visit1[x]) ++x;
      int y = arr[x];
      if (!i)
        res[n - 1] = str[y][0];
      else if (std::memcmp(res + n - i - 1, str[y] + len[y] - i - 1, i + 1))
        return;
    }
    ok = true;
    return;
  }
  for (int i = 0; i < 2; ++i) {
    int x = level * 2 + i, y = arr[x];
    if (!level || !std::memcmp(res, str[y], level)) {
      visit1[x] = true;
      visit2[y] = true;
      res[level] = str[y][level];
      dfs(level + 1);
      if (ok) return;
      visit1[x] = false;
      visit2[y] = false;
    }
  }
}
int main() {
  std::scanf("%d", &n);
  for (int i = 0; i < n * 2 - 2; ++i)
    std::scanf("%s", str[i]), len[i] = std::strlen(str[i]), arr[i] = i;
  std::sort(arr, arr + n * 2 - 2, [](int a, int b) { return len[a] < len[b]; });
  dfs(0);
  for (int i = 0; i < 2 * n - 2; ++i) std::putchar(visit2[i] ? 'P' : 'S');
  std::putchar('\n');
}
