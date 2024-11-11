#include <bits/stdc++.h>
using namespace std;
struct Binode {
  Binode *z, *o;
  void init() {
    z = NULL;
    o = NULL;
  }
} T;
int n;
long long a[100010], o[100010], s[70];
void add(long long x) {
  for (int i = 0; i < 61; i++) {
    s[i] = x & 1;
    x >>= 1;
  }
  Binode *p = &T;
  for (int i = 60; i >= 0; i--) {
    if (s[i]) {
      if (!(p->o)) {
        p->o = new Binode;
        p->o->init();
      }
      p = p->o;
    } else {
      if (!(p->z)) {
        p->z = new Binode;
        p->z->init();
      }
      p = p->z;
    }
  }
}
long long find(long long x) {
  for (int i = 0; i < 61; i++) {
    s[i] = x & 1;
    x >>= 1;
  }
  long long ans = 0;
  Binode *p = &T;
  for (int i = 60; i >= 0; i--) {
    if (s[i]) {
      if (p->z) {
        ans ^= (1LL << i);
        p = p->z;
      } else
        p = p->o;
    } else {
      if (p->o) {
        ans ^= (1LL << i);
        p = p->o;
      } else
        p = p->z;
    }
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  o[0] = 0;
  for (int i = 1; i <= n; i++) o[i] = o[i - 1] ^ a[i];
  long long x = 0, ans = 0;
  T.init();
  for (int i = n; i >= 0; i--) {
    add(x);
    ans = max(ans, find(o[i]));
    x = x ^ a[i];
  }
  printf("%I64d\n", ans);
  return 0;
}
