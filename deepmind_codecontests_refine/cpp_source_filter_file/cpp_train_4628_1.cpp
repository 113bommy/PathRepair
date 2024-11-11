#include <bits/stdc++.h>
using namespace std;
const int sN = 1 << 19;
long long v[sN], d[sN], l[sN], r[sN], s[sN], w[sN];
int n, m;
int t, Left, Right;
long long x;
void down(int a, int c1, int c2) {
  d[c1] += d[a];
  d[c2] += d[a];
  s[c1] += d[a] * w[c1];
  s[c2] += d[a] * w[c2];
  d[a] = 0;
  if (v[a] > 0) v[c1] = v[c2] = v[a];
}
long long get(int a) {
  if (Right < l[a] or r[a] < Left) return 0ll;
  if (Left <= l[a] and r[a] <= Right) return s[a];
  int c1 = a << 1, c2 = c1 + 1;
  down(a, c1, c2);
  return get(c1) + get(c2);
}
void update(int a) {
  if (Right < l[a] or r[a] < Left) return;
  if (Left <= l[a] and r[a] <= Right and v[a] > 0) {
    long long inc = x - v[a];
    if (inc < 0) inc = -inc;
    d[a] += inc;
    s[a] += inc * w[a];
    v[a] = x;
    return;
  }
  int c1 = a << 1, c2 = c1 + 1;
  down(a, c1, c2);
  update(c1);
  update(c2);
  s[a] = s[c1] + s[c2];
  if (v[c1] == v[c2])
    v[a] = v[c1];
  else
    v[a] = 0;
}
int main() {
  scanf("%d %d", &n, &m);
  int nn = 1;
  for (; nn < n; nn <<= 1)
    ;
  n = nn--;
  for (int i = 1; i <= n; i++)
    v[nn + i] = l[nn + i] = r[nn + i] = i, w[nn + i] = 1;
  for (int i = nn, j = i << 1; i > 0; i--, j = i << 1)
    l[i] = l[j], r[i] = r[j + 1], w[i] = w[j] << 1;
  for (; m--;) {
    cin >> t >> Left >> Right;
    if (t == 1) {
      cin >> x;
      update(1);
    } else {
      cout << get(1);
    }
  }
  return 0;
}
