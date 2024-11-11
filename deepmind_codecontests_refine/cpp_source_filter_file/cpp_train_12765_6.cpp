#include <bits/stdc++.h>
using namespace std;
long long n, m, a, b, ans, t, p, r, cnt[1000001], k[1000001], c, d;
struct abc {
  long long h, h1, h2;
  int id;
  bool type;
};
abc A[2000001];
bool operator<(abc i1, abc i2) { return i1.h1 - i1.h2 > i2.h1 - i2.h2; }
long long f(int x) {
  long long a1 = x * m, a2 = (r - x) * m, ans = 0;
  for (int i = 0; i < n; i++) cnt[i] = k[i];
  for (int i = 0; i < 2 * n; i++) {
    if (cnt[A[i].id] == 0) continue;
    if (A[i].type == 0) {
      if (a1 == 0) continue;
      if (cnt[A[i].id] > a1)
        ans += a1 * A[i].h, cnt[A[i].id] -= a1, a1 = 0;
      else
        a1 -= cnt[A[i].id], ans += cnt[A[i].id] * A[i].h, cnt[A[i].id] = 0;
    } else {
      if (a1 == 0) continue;
      if (cnt[A[i].id] > a2)
        ans += a2 * A[i].h, cnt[A[i].id] -= a2, a2 = 0;
      else
        a2 -= cnt[A[i].id], ans += cnt[A[i].id] * A[i].h, cnt[A[i].id] = 0;
    }
  }
  return ans;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> k[i] >> a >> b;
    t += k[i];
    A[i * 2].h = a;
    A[i * 2].h1 = a;
    A[i * 2].h2 = b;
    A[i * 2].id = i;
    A[i * 2].type = 0;
    A[i * 2 + 1].h = b;
    A[i * 2 + 1].h1 = b;
    A[i * 2 + 1].h2 = a;
    A[i * 2 + 1].id = i;
    A[i * 2 + 1].type = 1;
  }
  r = (t + m - 1) / m;
  sort(A, A + n * 2);
  a = 0, b = r;
  while (a < b) {
    c = a + (b - a) / 3;
    d = b - (b - a) / 3;
    if (f(c) == f(d))
      a = c + 1, b = d;
    else if (f(c) < f(d))
      a = c + 1;
    else
      b = d - 1;
  }
  cout << f(a) << endl;
}
