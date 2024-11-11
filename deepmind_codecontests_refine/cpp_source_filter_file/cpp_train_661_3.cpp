#include <bits/stdc++.h>
const long long INF = (1ll << 63) - 1ll;
const long double INFd = 28e14;
const int inf = (1ll << 31) - 1;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);
const long long mod = 7 + 1e9;
using namespace std;
void OUT(bool f) {
  if (f)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
void Out(bool f) {
  if (f)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
void out(bool f) {
  if (f)
    cout << "yes" << endl;
  else
    cout << "no" << endl;
}
inline int next_rand() { return abs((rand() << 15) + rand()); }
struct __debug__ {
  __debug__(string filename, bool f = false) {
    ios_base::sync_with_stdio(f);
    cin.tie(0);
    if (filename == "") return;
    string filein = filename + ".in";
    string fileout = filename + ".out";
    freopen(filein.c_str(), "r", stdin);
    freopen(fileout.c_str(), "w", stdout);
  }
  ~__debug__() {}
};
const int siz_MEM = 120;
__debug__ DEBUG("");
const int MB = (1 << 20);
const int MAX_MEM = siz_MEM * MB;
int mpos = 0;
char mem[MAX_MEM];
inline void* operator new(size_t n) {
  char* res = mem + mpos;
  mpos += n;
  return (void*)res;
}
inline void operator delete(void*) {}
void gen();
void solve();
void gen() { freopen("test.txt", "w", stdout); }
int main() {
  srand('M' + 'A' + 'S' + 'L' + '0' + 'F');
  srand(time(0));
  solve();
}
struct vert {
  vert* l;
  vert* r;
  int p;
  int val;
  int pro;
  vert() {
    l = r = nullptr;
    pro = 0;
    val = 0;
    p = 1;
  }
  vert(int x) {
    l = r = nullptr;
    pro = next_rand();
    val = x;
    p = 1;
  }
};
int getp(vert* v) {
  if (v == nullptr)
    return 0;
  else
    return v->p;
}
int getv(vert* v) {
  if (v == nullptr)
    return 0;
  else
    return v->val;
}
vert* a;
vert* b;
vert* c;
void split(vert* w, vert*& L, vert*& R, int x) {
  if (w == nullptr) {
    L = R = nullptr;
    return;
  }
  if (getp(w->l) < x) {
    split(w->r, w->r, R, x - getp(w->l) - 1);
    L = w;
    if (L != nullptr) L->p -= getp(R);
  } else {
    split(w->l, L, w->l, x);
    R = w;
    if (R != nullptr) R->p -= getp(L);
  }
}
vert* merge(vert* L, vert* R) {
  if (L == nullptr || R == nullptr) {
    return L ? L : R;
  }
  if (L->pro >= R->pro) {
    L->p += R->p;
    L->r = merge(L->r, R);
    return L;
  } else {
    R->p += L->p;
    R->l = merge(L, R->l);
    return R;
  }
}
void insert(vert*& v, int pos, int x) {
  c = new vert(x);
  a = nullptr;
  b = nullptr;
  split(v, a, b, pos);
  a = merge(a, c);
  v = merge(a, b);
}
int erase(vert*& v, int pos) {
  a = nullptr;
  b = nullptr;
  c = nullptr;
  split(v, a, b, pos + 1);
  split(a, a, c, pos);
  v = merge(a, b);
  return getv(c);
}
void piu(vert* v) {
  if (v == nullptr) return;
  piu(v->l);
  printf("%d ", getv(v) + 1);
  piu(v->r);
}
int n;
const int m = 200000;
int p[m + (int)(0.001 * m)];
void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    p[i] = i + 1;
  }
  for (int i = 2; i <= n; ++i) {
    p[n + i - 2] = p[(n + i - 2) - n % i];
    for (int j = n + i - 2 - n % i; j >= i; j -= i) {
      p[j] = p[j - i];
    }
  }
  for (int i = n - 1; i < n + n - 1; ++i) printf("%d ", p[i]);
}
