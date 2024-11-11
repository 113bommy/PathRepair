#include <bits/stdc++.h>
using namespace std;
bool fin[100013 << 2];
int co[100013 << 2];
long long su[100013 << 2];
long long ad[100013 << 2];
int n, m;
void down(int r, int le, int ri, int p, int q, int x);
void update(int r, int le, int ri, int p, int q, int x);
long long query(int r, int le, int ri, int p, int q);
int left(int r) { return r << 1; }
int right(int r) { return (r << 1) | 1; }
void init(int r, int le, int ri) {
  if (le == ri) {
    fin[r] = true;
    co[r] = le;
    return;
  }
  int mi = (le + ri) / 2;
  init(left(r), le, mi);
  init(right(r), mi + 1, ri);
}
void add(int r, int le, int ri, long long v, int c) {
  fin[r] = true;
  co[r] = c;
  ad[r] += v;
  su[r] += v * (ri - le + 1);
}
void split(int r, int le, int ri) {
  if (fin[r]) {
    int mi = (le + ri) / 2;
    add(left(r), le, mi, ad[r], co[r]);
    add(right(r), mi + 1, ri, ad[r], co[r]);
    fin[r] = false;
    ad[r] = 0;
  }
}
void down(int r, int le, int ri, int p, int q, int x) {
  split(r, le, ri);
  int mi = (le + ri) / 2;
  if (p <= mi) {
    update(left(r), le, mi, p, q, x);
  }
  if (mi < q) {
    update(right(r), mi + 1, ri, p, q, x);
  }
  su[r] = su[left(r)] + su[right(r)];
}
void update(int r, int le, int ri, int p, int q, int x) {
  if (p <= le && ri <= q) {
    if (fin[r]) {
      ad[r] += abs(x - co[r]);
      su[r] += abs((long long)x - co[r]) * ((long long)ri - le + 1);
      co[r] = x;
    } else {
      down(r, le, ri, p, q, x);
      fin[r] = true;
      co[r] = x;
    }
    return;
  }
  down(r, le, ri, p, q, x);
}
long long query(int r, int le, int ri, int p, int q) {
  if (p <= le && ri <= q) {
    return su[r];
  }
  split(r, le, ri);
  int mi = (le + ri) / 2;
  long long ret = 0;
  if (p <= mi) {
    ret += query(left(r), le, mi, p, q);
  }
  if (mi < q) {
    ret += query(right(r), mi + 1, ri, p, q);
  }
  return ret;
}
int main() {
  scanf("%d %d", &n, &m);
  init(1, 1, n);
  while (m--) {
    int type;
    int l, r, x;
    scanf("%d", &type);
    switch (type) {
      case 1:
        scanf("%d %d %d", &l, &r, &x);
        update(1, 1, n, l, r, x);
        break;
      case 2:
        scanf("%d %d", &l, &r);
        printf("%lld\n", query(1, 1, n, l, r));
        break;
    }
  }
  return 0;
}
