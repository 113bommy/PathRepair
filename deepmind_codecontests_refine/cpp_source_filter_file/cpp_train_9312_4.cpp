#include <bits/stdc++.h>
using namespace std;
map<int, int> p;
int A[500005], x, n, a, b, i, f1, s, t, f2, f[500005];
inline int find(int x) {
  if (f[x] != x) f[x] = find(f[x]);
  return f[x];
}
inline void add(int x, int y) { f[find(x)] = find(y); }
int main() {
  cin >> n >> a >> b;
  s = 0;
  t = n + 1;
  for (i = 1; i <= n + 1; ++i) f[i] = i;
  for (i = 1; i <= n; ++i) cin >> A[i], p[A[i]] = i;
  for (i = 1; i <= n; ++i) {
    x = A[i];
    f1 = p[a - x];
    f2 = p[b - x];
    if (!f1 && !f2) return cout << "No", 0;
    if (!f1)
      add(i, s), add(s, f2);
    else if (!f2)
      add(i, t), add(t, f1);
    else
      add(i, f1), add(i, f2);
  }
  s = find(s);
  t = find(t);
  if (s == t) return cout << "No", 0;
  cout << "Yes\n";
  for (i = 1; i <= n; ++i) cout << (find(i) == s) << " ";
}
