#include <bits/stdc++.h>
using namespace std;
int sz;
struct st {
  long long a, b, l, val;
  st() {
    a = 0, b = 0;
    l = -1;
    val = -1;
  }
};
st v[100005];
long long caut(long long a, long long b, long long x) {
  while (a <= b) {
    long long mij = (a + b) / 2;
    if (v[mij].a <= x && x <= v[mij].b) return mij;
    if (v[mij].b < x) {
      a = mij + 1;
    } else
      b = mij - 1;
  }
}
long long solve(long long ind, long long x) {
  if (v[ind].val > 0) return v[ind].val;
  long long p = (x - v[ind].a + 1) % v[ind].l;
  if (!p) p = v[ind].l;
  long long a = 1, b = ind;
  ind = caut(a, b, p);
  return solve(ind, p);
}
int main() {
  int n, m, ind = 1;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int op;
    cin >> op;
    if (op == 1) {
      cin >> v[++sz].val;
      v[sz].a = v[sz - 1].b + 1;
      v[sz].b = v[sz].a;
    }
    if (op == 2) {
      long long l, c;
      cin >> l >> c;
      v[++sz].l = l;
      v[sz].a = v[sz - 1].b + 1;
      v[sz].b = v[sz].a + l * c - 1;
    }
  }
  cin >> m;
  for (; m--;) {
    int x;
    cin >> x;
    for (; !(v[ind].a <= x && x <= v[ind].b); ++ind)
      ;
    cout << solve(ind, x) << " ";
  }
  return 0;
}
