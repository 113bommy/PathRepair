#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  int ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
void print(vector<int> x) {
  for (int i = 0; i < (int)x.size(); i++)
    printf("%d%c", x[i], " \n"[i == (int)x.size() - 1]);
}
int a[500005], mn[500005][20], mx[500005][20], lg[500005], Ans[500005], n;
pair<int, int> query(int l, int r) {
  int t = lg[r - l + 1];
  return make_pair(min(mn[l][t], mn[r - (1 << t) + 1][t]),
                   max(mx[l][t], mx[r - (1 << t) + 1][t]));
}
signed main() {
  for (int i = 2; i < 500005; i++) lg[i] = lg[i / 2] + 1;
  cin >> n;
  for (int i = 1; i <= n; i++) a[i] = read();
  a[0] = a[1], a[n + 1] = a[n];
  for (int i = 0; i <= n; i++) mn[i][0] = max(a[i], a[i + 1]);
  for (int i = 0; i <= n; i++) mx[i][0] = min(a[i], a[i + 1]);
  for (int i = 1; i <= 19; i++)
    for (int j = 0; j + (1 << i) - 1 <= n; j++)
      mn[j][i] = min(mn[j][i - 1], mn[j + (1 << (i - 1))][i - 1]);
  for (int i = 1; i <= 19; i++)
    for (int j = 0; j + (1 << i) - 1 <= n; j++)
      mx[j][i] = max(mx[j][i - 1], mx[j + (1 << (i - 1))][i - 1]);
  int maxn = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == a[i - 1] || a[i] == a[i + 1]) {
      Ans[i] = a[i];
      continue;
    }
    int l = 1, r = min(i, n - i + 1), ans = 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      auto [A, B] = query(i - mid, i + mid - 1);
      if (B < A)
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    maxn = max(maxn, ans);
    auto [A, B] = query(i - ans, i + ans - 1);
    if ((ans % 2 == 0) == (a[i] > a[i - 1]))
      Ans[i] = A;
    else
      Ans[i] = B;
  }
  cout << maxn << endl;
  for (int i = 1; i <= n; i++) printf("%d%c", Ans[i], " \n"[i == n]);
  return 0;
}
