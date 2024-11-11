#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void cmin(T &a, T b) {
  ((a > b) && (a = b));
}
template <class T>
inline void cmax(T &a, T b) {
  ((a < b) && (a = b));
}
char IO;
template <class T = int>
T rd() {
  T s = 0;
  int f = 0;
  while (!isdigit(IO = getchar())) f |= IO == '-';
  do s = (s << 1) + (s << 3) + (IO ^ '0');
  while (isdigit(IO = getchar()));
  return f ? -s : s;
}
const int N = 1e6 + 10, INF = 1e9 + 10;
const long double eps = 1e-20;
int n;
long long k;
long double m;
struct Node {
  long double x, y;
  Node(long double x = 0, long double y = 0) : x(x), y(y) {}
  bool operator<(const Node __) const {
    return x < __.x - eps || (fabs(x - __.x) < eps && y > __.y);
  }
  Node operator-(const Node _) const { return Node(x - _.x, y - _.y); }
  long double operator^(const Node _) const { return x * _.y - y * _.x; }
  long double operator[](const long double k) { return k * x + y; }
  Node operator*(const Node _) { return Node(x * _.x, _.x * y + _.y); }
} A[N], S[N], Pow[35];
long double Cross(Node a, Node b) { return (b.y - a.y) / (a.x - b.x); }
int T;
int main() {
  n = rd(), k = rd<long long>();
  for (int i = 1, iend = n; i <= iend; ++i) {
    long double a = rd(), b = rd(), p;
    cin >> p;
    cmax(m, p * b), A[i] = Node(1 - p, a * p);
  }
  for (int i = 1, iend = n; i <= iend; ++i) A[i].y = m - A[i].y;
  sort(A + 1, A + n + 1);
  long double miy = 1e20;
  for (int i = 1, iend = n; i <= iend; ++i) {
    if (miy < A[i].y + eps) continue;
    miy = A[i].y;
    while (T > 1 && ((A[i] - S[T]) ^ (S[T - 1] - S[T])) < eps) T--;
    S[++T] = A[i];
  }
  long double g = 0, s = k * m;
  S[0].y = 1e40;
  while (k) {
    while (T > 1 && S[T - 1][g] <= S[T][g] + eps) T--;
    Pow[0] = S[T];
    for (int i = 1; (1ll << i) <= k; ++i) Pow[i] = Pow[i - 1] * Pow[i - 1];
    for (int i = 34, iend = 0; i >= iend; --i)
      if ((1ll << i) <= k && S[T - 1][Pow[i][g]] >= S[T][Pow[i][g]] + eps)
        k -= 1ll << i, g = Pow[i][g];
    if (k && S[T - 1][g] >= S[T][g] + eps) k--, g = Pow[0][g];
  }
  cout << fixed << setprecision(10) << s - g << endl;
}
