#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int n;
int a[N], b[N];
int s[N];
vector<int> ans;
int main() {
  cin >> n;
  static char str[N];
  scanf("%s", str + 1);
  for (int i = 1; i <= n; i++) a[i] = str[i] - '0';
  scanf("%s", str + 1);
  for (int i = 1; i <= n; i++) b[i] = str[i] - '0';
  long long Ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = a[i], y = b[i];
    s[i] = y - (x + s[i - 1]), Ans += abs(s[i]);
  }
  if (s[n]) return puts("-1"), 0;
  static bool ex[N];
  queue<int> q;
  for (int i = 1; i < n; i++) {
    if (s[i] > 0 && a[i + 1] != 9) q.push(i), ex[i] = true;
    if (s[i] < 0 && a[i + 1]) q.push(i), ex[i] = true;
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    ex[x] = false;
    if (s[x] < 0)
      --a[x], --a[x + 1], ans.push_back(-x), ++s[x];
    else
      ++a[x], ++a[x + 1], ans.push_back(x), --s[x];
    if (s[x] > 0 && a[x + 1] != 9) q.push(x), ex[x] = true;
    if (s[x] < 0 && a[x + 1]) q.push(x), ex[x] = true;
    --x;
    if (!ex[x]) {
      if (s[x] > 0 && a[x + 1] != 9) q.push(x), ex[x] = true;
      if (s[x] < 0 && a[x + 1]) q.push(x), ex[x] = true;
    }
    if (ans.size() > 1e5) break;
  }
  if (ans.size() <= 1e5) {
    for (int i = 1; i <= n; i++)
      if (a[i] != b[i]) return puts("-1"), 0;
  }
  if (ans.size() > 1e5) ans.resize(1e5);
  cout << Ans << '\n';
  for (int z : ans) {
    if (z < 0)
      cout << -z << " " << -1 << '\n';
    else
      cout << z << " " << 1 << '\n';
  }
  return 0;
}
