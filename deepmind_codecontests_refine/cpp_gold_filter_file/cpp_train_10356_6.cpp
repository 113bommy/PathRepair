#include <bits/stdc++.h>
using namespace std;
struct pt {
  long double x, y;
  pt() {}
  pt(long double _x, long double _y) : x(_x), y(_y) {}
  pt operator+(const pt &p) const { return pt(x + p.x, y + p.y); }
  pt operator-(const pt &p) const { return pt(x - p.x, y - p.y); }
  pt operator*(long double c) const { return pt(x * c, y * c); }
  pt operator/(long double c) const { return pt(x / c, y / c); }
  void operator+=(const pt &p) {
    x += p.x;
    y += p.y;
  };
  void operator-=(const pt &p) {
    x -= p.x;
    y -= p.y;
  };
  void operator*=(long double c) {
    x *= c;
    y *= c;
  };
  void operator/=(long double c) {
    x /= c;
    y /= c;
  };
  long double operator/(const pt &p) const { return (x * p.y - y * p.y); }
  long double operator*(const pt &p) const { return (x * p.x + y * p.y); }
  long double length() { return sqrtl(x * x + y * y); }
  long double angle() { return atan2(y, x); }
};
struct treap {
  int key, p, cnt;
  treap *l, *r;
  treap(int _key)
      : key(_key),
        p(((RAND_MAX < 1000000000) ? (rand() * rand()) : (rand()))),
        cnt(1),
        l(NULL),
        r(NULL) {}
};
int getcnt(treap *t) {
  if (t) return t->cnt;
  return 0;
}
treap *upd(treap *t) {
  if (!t) return t;
  t->cnt = 1 + getcnt(t->l) + getcnt(t->r);
}
void split(treap *t, int key, treap *&l, treap *&r) {
  if (!t) return void(l = r = NULL);
  if (t->key < key)
    split(t->l, key, l, t->l), r = t;
  else
    split(t->r, key, t->r, r), l = t;
  upd(t);
}
treap *merge(treap *l, treap *r) {
  if (!l || !r) return max(l, r);
  if (l->p > r->p) {
    l->r = merge(l->r, r);
    return upd(l);
  } else {
    r->l = merge(l, r->l);
    return upd(r);
  }
}
struct rmq {
  int l, r, MaxInd;
  int Max, Add;
  rmq *L, *R;
  rmq(int b, int e) {
    l = b;
    r = e;
    MaxInd = l;
    Max = Add = 0;
    if (b != e) {
      L = new rmq(b, (b + e) / 2);
      R = new rmq((b + e) / 2 + 1, e);
    }
  }
  void SET(int i, int x) {
    if (l == r)
      Max = x;
    else {
      if (i <= L->r)
        L->SET(i, x);
      else
        R->SET(i, x);
      Max = max(L->Max + L->Add, R->Max + R->Add);
      if (Max == L->Max + L->Add)
        MaxInd = L->MaxInd;
      else
        MaxInd = R->MaxInd;
    }
  }
  void ADD(int b, int e, int x) {
    if (b > r || e < l) return;
    if (b <= l && e >= r)
      Add += x;
    else {
      L->ADD(b, e, x);
      R->ADD(b, e, x);
      Max = max(L->Max + L->Add, R->Max + R->Add);
      if (Max == L->Max + L->Add)
        MaxInd = L->MaxInd;
      else
        MaxInd = R->MaxInd;
    }
  }
  int MAX(int b, int e) {
    if (b > r || e < l) return -1000000000;
    if (b <= l && e >= r)
      return Max + Add;
    else {
      return max(L->MAX(b, e), R->MAX(b, e)) + Add;
    }
  }
  pair<int, int> MAX_IND(int b, int e) {
    if (b > r || e < l) return make_pair(-1000000000, -1000000000);
    if (b <= l && e >= r)
      return make_pair(Max + Add, MaxInd);
    else {
      pair<int, int> ans = max(L->MAX_IND(b, e), R->MAX_IND(b, e));
      ans.first += Add;
      return ans;
    }
  }
};
set<long double> Set;
long long n, m;
int main() {
  cin >> n >> m;
  long long c, b, summ = 0;
  for (b = 1; b <= n; ++b) {
    summ += min(b * b, m) - b;
    if (b * b > m) summ += floor((sqrtl(b * b - m - 1))) + 1;
  }
  summ *= 2;
  summ += min(n, (m + 1) / 2) + min(n - 1, m / 4);
  cout << summ;
  return 0;
  for (b = 1; b <= n; ++b) {
    int up = min(m, b * b);
    for (c = 1; c <= up; ++c) {
      int now = Set.size();
      Set.insert(-b + sqrtl(b * b - c));
      Set.insert(-b - sqrtl(b * b - c));
      if (now != Set.size() - 2)
        cout << "b = " << b << " c = " << c << " " << Set.size() - now << endl;
      else
        cout << "all ok\n";
    }
  }
  cout << Set.size();
  return 0;
}
