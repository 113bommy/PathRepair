#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, v, start = 1;
int a[4 * MAXN];
bool ok[MAXN], dif1;
void Update(int poz) {
  a[poz] = min(a[poz + poz], a[poz + poz + 1]);
  if (poz > 1) Update(poz / 2);
}
int Query(int st, int dr) {
  int ans = 2e9;
  if (st & 1) ans = a[st++];
  if (!(dr & 1)) {
    ans = min(ans, a[dr]);
    --dr;
  }
  if (st > dr) return ans;
  int aux = Query(st / 2, dr / 2);
  return min(ans, aux);
}
int main() {
  cin >> n;
  while (start < n) start <<= 1;
  for (int i = 1; i <= n; ++i) {
    cin >> v;
    if (v != 1) dif1 = true;
    if (!ok[v]) {
      int q = Query(start, start + v - 2);
      if (q > a[v + start - 1]) ok[v] = true;
    }
    a[v + start - 1] = i;
    Update((v + start - 1) / 2);
  }
  if (!dif1) {
    cout << 1;
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    if (ok[i]) continue;
    int q = Query(start, start + i - 2);
    if (q > a[i + start - 1]) ok[i] = true;
  }
  for (int i = 1; i <= n + 1; ++i) {
    if (!ok[i]) {
      cout << i;
      return 0;
    }
  }
  return 0;
}
