#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int p[maxn], q[maxn], c[maxn], n, a, b;
int cmp(int x, int y) { return x > y; }
int main() {
  cin >> n >> a >> b;
  int t = a + b;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> q[i];
  }
  for (int i = 0; i < n; i++) {
    c[i] = abs(p[i] - q[i]);
  }
  sort(c, c + n, cmp);
  while (t) {
    c[0] = abs(c[0] - 1);
    t--;
    sort(c, c + n, cmp);
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    res += c[i] * c[i];
  }
  cout << res << endl;
  return 0;
}
