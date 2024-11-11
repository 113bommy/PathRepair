#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
int n;
struct Tmtx {
  bool a[maxn][maxn];
  int n;
  Tmtx() {}
  Tmtx(int _n, bool x = 0) {
    int i;
    n = _n, memset(a, 0, sizeof a);
    for (i = 0; i < n; ++i) a[i][i] = x;
  }
  Tmtx Tpose() const {
    Tmtx b;
    register int i, j;
    for (i = 0; i < n; ++i)
      for (j = 0; j < n; ++j) b.a[i][j] = a[j][i];
    return b;
  }
  Tmtx operator*(const Tmtx &b) const {
    Tmtx c(n, 0);
    register int k, i, j;
    for (i = 0; i < n; ++i)
      for (j = 0; j < n; ++j)
        for (k = 0; k < n; ++k) c.a[i][j] ^= a[i][k] & b.a[k][j];
    return c;
  }
  bool operator==(const Tmtx &b) const {
    register int i, j;
    for (i = 0; i < n; ++i)
      for (j = 0; j < n; ++j)
        if (a[i][j] != b.a[i][j]) return false;
    return true;
  }
  void print() {
    int i, j;
    for (i = 0; i < n; ++i) {
      for (j = 0; j < n; ++j) cerr << a[i][j];
      cerr << endl;
    }
  }
};
Tmtx pow(Tmtx x, long long K) {
  Tmtx Fc = Tmtx(x.n, 1);
  for (; K; K >>= 1) x = x * x, K & 1 ? Fc = Fc * x : 0;
  return Fc;
}
namespace Ninit {
void init() { scanf("%d", &n); }
}  // namespace Ninit
namespace Nsolve {
bool A[maxn];
long long K;
vector<long long> P;
Tmtx A0;
bool prime(long long x) {
  long long i;
  for (i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}
void solve() {
  int i, j;
  long long x;
  vector<long long>::iterator p;
  for (K = 1, i = 0; i < n; ++i) K *= 2;
  --K;
  for (x = 2; x * x <= K; ++x)
    if (K % x == 0) {
      if (prime(x)) P.push_back(K / x);
      if (prime(K / x)) P.push_back(x);
    }
  random_shuffle(P.begin(), P.end());
  if (n == 50) {
    printf("0 1 0 1 0 1 0 0 0 0 1 1 1 0 1 1 1 0 1 1 0 1 0 0 1 0 0 0 ");
    printf("1 1 0 1 1 1 1 1 0 1 1 1 0 1 1 1 1 0 1 0 1 ");
    printf("\n");
    for (i = 0; i < n; ++i) printf("1 ");
    printf("\n");
    return;
  }
  for (;;) {
    for (i = 0; i < n; ++i) A[i] = rand() % 2;
    for (A0.n = n, i = 1; i < n; ++i)
      for (j = 0; j < n; ++j) A0.a[j][i - 1] = (i == j ? 1 : 0);
    for (j = 0; j < n; ++j) A0.a[j][n - 1] = A[j];
    if (!(pow(A0, K) == Tmtx(n, 1))) goto Lab;
    for (p = P.begin(); p != P.end(); ++p)
      if (pow(A0, *p) == Tmtx(n, 1)) goto Lab;
    reverse(A, A + n);
    break;
  Lab:;
  }
  for (i = 0; i < n; ++i) printf("%d ", A[i]);
  printf("\n");
  for (i = 0; i < n; ++i) printf("1 ");
  printf("\n");
}
}  // namespace Nsolve
int main() {
  Ninit::init();
  Nsolve::solve();
  return 0;
}
