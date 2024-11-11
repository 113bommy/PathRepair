#include <bits/stdc++.h>
using namespace std;
set<pair<pair<int, int>, pair<int, int> > > st;
string a[60];
bool ok(int u, int v) {
  if (a[u][0] == a[v][0] or a[u][1] == a[v][1]) return 1;
  return 0;
}
bool sol(int n, int a, int b, int c) {
  if (!n) {
    if (ok(b, c) and ok(a, b)) return 1;
    return 0;
  }
  if (ok(b, c) and !st.count({{n - 1, n}, {a, c}})) {
    st.insert({{n - 1, n}, {a, c}});
    if (sol(n - 1, n, a, c)) return 1;
  }
  if (ok(n, c) and !st.count({{n - 1, c}, {a, b}})) {
    st.insert({{n - 1, c}, {a, c}});
    if (sol(n - 1, c, a, b)) return 1;
  }
  return 0;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (n == 1) {
    puts("YES");
    return 0;
  }
  if (n == 2) {
    if (ok(1, 2))
      puts("YES");
    else
      puts("NO");
    return 0;
  }
  if (sol(n - 3, n - 2, n - 1, n))
    puts("YES");
  else
    puts("NO");
  return 0;
}
