#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 * 1000 + 10, maxm = (1 << 17), mod = (int)1e9 + 7,
          hash = 701, maxim = (1 << 24) + 10, inf = (1 << 29) + 3;
const double pi = 3.14159265359, ee = 2.71828;
int t[2 * maxm], d[2 * maxm], cnt;
void update(int n, int p, int dd) {
  t[p] = n, d[p] = dd;
  for (int i = p / 2; i; i /= 2)
    t[i] = max(t[i * 2], t[i * 2 + 1]), d[i] = max(d[i * 2], d[i * 2 + 1]);
}
void query(int n, int v) {
  if (v >= maxm) return;
  if (t[2 * v + 1] > n)
    query(n, 2 * v + 1);
  else {
    cnt = max(cnt, d[2 * v + 1]);
    query(n, 2 * v);
  }
}
int main() {
  ios::sync_with_stdio(0);
  int n, a;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a, cnt = -1;
    if (t[1] > a) query(a, 1);
    update(a, i + maxm, cnt + 1);
  }
  cout << d[1] << endl;
  return 0;
}
