#include <bits/stdc++.h>
using namespace std;
void addmod(int &a, long long b) {
  a = (a + b);
  if (a >= 1000000007) a -= 1000000007;
}
void mulmod(int &a, long long b) { a = (a * b) % 1000000007; }
template <class T>
bool domin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
bool domax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
int gi() {
  int a;
  scanf("%d", &a);
  return a;
}
long long gll() {
  long long a;
  scanf("%lld", &a);
  return a;
}
template <typename T>
class fenwick {
  int n;
  vector<T> a;

 public:
  fenwick(int n = 0) : n(n), a(n + 1, 0) {}
  T getsum(int ix) {
    T ret = 0;
    for (int i = ix; i > 0; i -= (i & (-i))) ret += a[i];
    return ret;
  }
  T getsumbw(int ia, int ib) { return (getsum(ib) - getsum(ia - 1)); }
  void add(int ix, T val) {
    for (int i = ix; i <= n; i += (i & (-i))) a[i] += val;
  }
  T getval(int ix) {
    T ret = a[ix];
    if (ix > 0) {
      int tmp = ix - (ix & (-ix));
      ix--;
      while (ix != tmp) {
        ret -= a[ix];
        ix -= (ix & (-ix));
      }
    }
    return ret;
  }
};
int getix(char c) {
  if (c == 'A') return 0;
  if (c == 'T') return 1;
  if (c == 'G') return 2;
  if (c == 'C') return 3;
  return -1;
}
fenwick<int> vf[4][11][11];
int main() {
  char *s, *es;
  s = new char[100007];
  es = new char[13];
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < 4; i++)
    for (int k = 0; k < 11; k++)
      for (int j = 0; j < 11; j++) {
        vf[i][j][k] = fenwick<int>(n + 1);
      }
  for (int i = 0; i < n; i++)
    for (int j = 1; j < 11; j++) {
      vf[getix(s[i])][j][i % j].add(i + 1, 1);
    }
  int q = gi();
  for (int qi = 0; qi < q; qi++) {
    int t = gi(), l = gi();
    if (t == 1) {
      scanf(" %s", es);
      l--;
      for (int j = 1; j < 11; j++) {
        vf[getix(s[l])][j][l % j].add(l + 1, -1);
        vf[getix(es[0])][j][l % j].add(l + 1, 1);
      }
      s[l] = es[0];
    } else {
      int r;
      scanf("%d %s", &r, es);
      int el = strlen(es), mt = 0;
      for (int j = 0; j < el; j++) {
        int nl = l + j;
        if (nl > r) continue;
        if (nl > n) continue;
        nl--;
        mt += vf[getix(es[j])][el][nl % el].getsumbw(nl + 1, r);
      }
      cout << mt << endl;
    }
  }
  return 0;
}
