#include <bits/stdc++.h>
using namespace std;
int main(void) {
  srand(time(0));
  cout << fixed << setprecision(7);
  cerr << fixed << setprecision(7);
  static char s[1 << 20];
  static char v[1 << 20];
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cin >> (s + 1);
  int n = strlen(s + 1);
  int m;
  cin >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    static int p[1 << 20];
    static int D[20][1 << 20];
    int cur = 0;
    for (int i = 1; i <= b; ++i)
      for (int j = i; j <= a; j += b) p[++cur] = j;
    while (cur < n) p[++cur] = cur;
    p[++cur] = p[1];
    for (int i = 1; i <= n; ++i) p[i] = p[i + 1];
    for (int i = 1; i <= n; ++i) D[0][i] = p[i];
    for (int k = 1; k < 20; ++k)
      for (int i = 1; i <= n; ++i) D[k][i] = D[k - 1][D[k - 1][i]];
    auto f = [&](int a, int b) {
      for (int k = 0; k < 19; ++k)
        if ((b >> k) & 1) a = D[k][a];
      return a;
    };
    for (int i = 1; i <= n; ++i) {
      int now = f(i, n - a + 1);
      if (i < a)
        p[i + (n - a + 1)] = now;
      else
        p[i - (a - 1)] = now;
    }
    for (int i = 1; i <= n; ++i) v[i] = s[p[i]];
    for (int i = 1; i <= n; ++i) s[i] = v[i];
    cout << (s + 1) << '\n';
  }
  cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms"
       << '\n';
  return 0;
}
