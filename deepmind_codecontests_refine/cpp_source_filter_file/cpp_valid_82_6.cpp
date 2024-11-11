#include <bits/stdc++.h>
using namespace std;
const int N = 5e6;
int a[N], b[N];
int qzh[N], hzh[N];
int n, q;
vector<int> vec[N];
inline char readchar() {
  char c = getchar();
  while (c != '+' && c != '-') c = getchar();
  return c;
}
int read() {
  int x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return x;
}
void solve() {
  n = read(), q = read();
  for (int i = 1; i <= n; i++) {
    char c = readchar();
    a[i] = (c == '+') ? +1 : -1;
    b[i] = (i % 2 == 0) ? -a[i] : a[i];
    qzh[i] = qzh[i - 1] + b[i];
  }
  hzh[n + 1] = 0;
  for (int i = n; i >= 1; i--) hzh[i] = hzh[i + 1] + b[i];
  for (int i = 1; i <= n; i++)
    vec[qzh[i - 1] - hzh[i + 1] + 2 * n].push_back(i);
  for (int l, r, i = 1; i <= q; i++) {
    l = read(), r = read();
    vector<int> ans;
    if ((r - l + 1) % 2 == 0)
      if (qzh[l - 1] == qzh[r]) {
        printf("0");
        continue;
      } else {
        ans.push_back(r);
        r--;
      }
    vector<int>& v = vec[qzh[l - 1] - hzh[r + 1] + 2 * n];
    ans.push_back(v[lower_bound(v.begin(), v.end(), l) - v.begin()]);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
    printf("\n");
    ans.clear();
  }
  for (int i = 0; i <= 4 * n; i++) vec[i].clear();
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
