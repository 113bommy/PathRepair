#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const long long ooo = 9223372036854775807ll;
const int _cnt = 1000 * 1000 + 7;
const int _p = 1000 * 1000 * 1000 + 7;
const int N = 100005;
const double PI = acos(-1.0);
const double eps = 1e-9;
int o(int x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void file_put() {
  freopen("filename.in", "r", stdin);
  freopen("filename.out", "w", stdout);
}
long long Pow(long long x, long long k, long long p) {
  long long ans = 1;
  for (; k; k >>= 1, (x *= x) %= _p)
    if (k & 1) (ans *= x) %= _p;
  return ans;
}
const int _M = 100;
template <class V = long long, long long _p = (long long)1e9 + 7>
struct L_B {
  V base[_M + 5][_M + 5], a[_M + 5], b[_M + 5], t;
  int D, cnt;
  long long pp = 13331;
  inline void Init(int _D) {
    D = _D, memset(base, 0, sizeof(base));
    cnt = 0;
  }
  inline bool I(V a[]) {
    memset(b, 0, sizeof(b));
    for (int i = (0); i <= (D - 1); ++i)
      if (a[i]) {
        if (!base[i][i]) {
          t = Pow(a[i], _p - 2, _p);
          for (int j = (i); j <= (D - 1); ++j)
            base[i][j] = a[j] = (long long)a[j] * t % _p;
          cnt++;
          return 1;
        }
        b[i] = a[i];
        for (int j = (D - 1); j >= (i); --j)
          a[j] = (a[j] - (long long)a[i] * base[i][j] % _p) % _p;
      }
    return 0;
  }
  inline bool Insert(V _a[], V _b[] = NULL) {
    memcpy(a, _a, D * sizeof(V));
    bool tt = I(a);
    if (!tt && _b) memcpy(_b, b, D * sizeof(V));
    return tt;
  }
  inline void Normalize() {
    for (int i = (0); i <= (D - 1); ++i)
      if (base[i][i])
        for (int j = (0); j <= (i - 1); ++j)
          if (base[j][i])
            for (int k = (D - 1); k >= (i); --k)
              base[j][k] =
                  (base[j][k] - (long long)base[i][k] * base[j][i] % _p) % _p;
    for (int i = (0); i <= (D - 1); ++i)
      for (int j = (0); j <= (D - 1); ++j)
        if (base[i][j] < 0) base[i][j] += _p;
  }
  inline L_B &Clone() const {
    L_B p;
    for (int i = (0); i <= (D - 1); ++i)
      for (int j = (0); j <= (D - 1); ++j) p.base[i][j] = base[i][j];
    p.D = D, p.cnt = cnt;
    return p;
  }
  friend L_B &Merge(const L_B &a, const L_B &b) {
    L_B c = a.Clone();
    for (int i = (0); i <= (b.D - 1); ++i) c.Insert(b.base[i]);
    return c;
  }
  inline V Get_Hash_Code() const {
    V ans = D ^ cnt % _p;
    for (int i = (0); i <= (D - 1); ++i)
      for (int j = (0); j <= (D - 1); ++j)
        ans = ((long long)ans * pp + base[i][j]) % _p;
    return ans;
  }
  friend bool operator==(const L_B &_a, const L_B &_b) {
    L_B a = _a.Clone(), b = _b.Clone();
    a.Normalize(), b.Normalize();
    return a.Get_Hash_Code() == b.Get_Hash_Code();
  }
  inline void Print() const {
    puts("\n_______________\n\n");
    cout << "D"
         << " => " << (D) << endl;
    puts("\n_______________\n\n");
    cout << "cnt"
         << " => " << (cnt) << endl;
    puts("\n_______________\n\n");
    cout << "base"
         << ":\n";
    for (int i = (0); i <= (D - 1); ++i)
      for (int j = (0); j <= (D - 1); ++j)
        cout << "base"
             << "[" << (i) << "][" << (j) << "]= " << base[i][j]
             << ((j == D - 1) ? "\n\n" : "    ");
  }
};
int m, d, k, id = 0;
L_B<> B;
long long a[15], ret;
map<long long, int> M;
int main() {
  scanf("%d%d", &m, &d);
  while (m--) {
    scanf("%d", &k), B.Init(d);
    for (int i = (1); i <= (k); ++i) {
      for (int j = (0); j <= (d - 1); ++j) scanf("%I64d", &a[j]);
      B.Insert(a);
    }
    B.Normalize();
    ret = B.Get_Hash_Code();
    if (!M.count(ret)) M[ret] = ++id;
    printf("%d ", M[ret]);
  }
  return 0;
}
