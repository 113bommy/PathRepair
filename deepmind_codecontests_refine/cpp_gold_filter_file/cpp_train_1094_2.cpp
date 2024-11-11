#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-16;
const int N = 1234567;
const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
long long p[N];
long long s[N];
int n;
int a[N];
int bi, bj;
struct Fraction {
  long long a, b;
  inline bool operator<(const Fraction &other) const {
    return a * other.b < b * other.a;
  }
};
Fraction best = {-1, 1};
inline Fraction get(int i, int j) {
  long long val = p[i] - p[i - j - 1] + s[n - j + 1];
  Fraction cur = {val, 2LL * j + 1LL};
  cur.a -= a[i] * cur.b;
  if (best < cur) {
    best = cur;
    bi = i;
    bj = j;
  }
  return cur;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] + a[i];
  }
  for (int i = n; i >= 1; i--) {
    s[i] = s[i + 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    int l = 0;
    int r = min(i - 1, n - i);
    while (r - l > 2) {
      int m1 = (l + l + r) / 3;
      int m2 = (r + r + l) / 3;
      Fraction g1 = get(i, m1);
      Fraction g2 = get(i, m2);
      if (g1 < g2) {
        l = m1;
      } else {
        r = m2;
      }
    }
    for (int j = l; j <= r; j++) {
      get(i, j);
    }
  }
  vector<int> ans;
  for (int i = bi - bj; i <= bi; i++) {
    ans.push_back(a[i]);
  }
  for (int i = n - bj + 1; i <= n; i++) {
    ans.push_back(a[i]);
  }
  printf("%d\n", ((int)ans.size()));
  for (int i = 0; i < ((int)ans.size()); i++) {
    if (i > 0) {
      putchar(' ');
    }
    printf("%d", ans[i]);
  }
  putchar('\n');
  return 0;
}
