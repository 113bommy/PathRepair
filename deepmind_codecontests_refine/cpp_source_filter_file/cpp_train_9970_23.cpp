#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void _read(T& x) {
  char ch = getchar();
  bool sign = true;
  while (!isdigit(ch)) {
    if (ch == '-') sign = false;
    ch = getchar();
  }
  for (x = 0; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
  if (!sign) x = -x;
}
bool mark[1505];
int n, ans[1505], lim;
int d[5] = {0, 1, 5, 10, 50};
void dfs(int id, int x, int tot) {
  if (x == lim + 1) {
    mark[tot] = true;
    return;
  }
  for (int i = id; i <= 4; i++) dfs(i, x + 1, tot + d[i]);
}
int main() {
  cin >> n;
  for (int i = 1; i <= 11; i++) {
    lim = i;
    memset(mark, 0, sizeof(mark));
    dfs(1, 1, 0);
    int temp = 0;
    for (int j = 1; j <= i * 50; j++)
      if (mark[j]) temp++;
    ans[i] = temp;
  }
  if (n <= 11) {
    cout << ans[n];
    return 0;
  }
  cout << 1ll * 49 * (n - 11) + ans[10];
}
