#include <bits/stdc++.h>
using namespace std;
int a[1000010], sta[1000010], top, n, t, x;
bool dfs(int v) {
  while (top) {
    int p = sta[--top];
    if (a[p] == -v)
      return true;
    else {
      a[p] = -a[p];
      if (!dfs(a[p])) return false;
    }
  }
  return false;
}
bool sol() {
  for (int i = 1; i <= n; i++) {
    if (a[i] < 0) {
      if (!dfs(a[i])) return false;
    } else
      sta[top++] = i;
  }
  while (top) {
    x = sta[--top];
    a[x] = -a[x];
    if (!dfs(a[x])) return false;
  }
  if (top) return false;
  return true;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> t;
  for (int i = 0; i < t; i++) cin >> x, a[x] = -a[x];
  if (sol()) {
    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << endl;
  } else
    cout << "NO\n";
  return 0;
}
