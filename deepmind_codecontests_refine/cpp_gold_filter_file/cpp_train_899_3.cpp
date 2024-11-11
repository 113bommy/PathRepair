#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-10;
const double PI = acos(-1.0);
template <class T>
T gcd(T a, T b) {
  for (T c; b; c = a, a = b, b = c % b)
    ;
  return a;
}
template <class T>
void out(const vector<T> &a) {
  for (int i = 0; i < ((int)(a).size()); ++i) cout << a[i] << " ";
  cout << endl;
}
int countbit(int n) { return n == 0 ? 0 : 1 + countbit(n & (n - 1)); }
const int d8[8][2] = {{1, 0}, {-1, 0},  {0, 1},  {0, -1},
                      {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
const int d4[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
inline int dcmp(double x) { return (x > EPS) - (x < -EPS); }
inline double cross(const complex<double> &a, const complex<double> &b) {
  return (conj(a) * b).imag();
}
inline double dot(const complex<double> &a, const complex<double> &b) {
  return (conj(a) * b).real();
}
const int N = 10000;
pair<int, int> a[N];
vector<pair<int, int> > b;
void doit(int L, int R) {
  int mid = (L + R) / 2;
  if (R - L == 1)
    return;
  else if (R - L == 2) {
    b.push_back(pair<int, int>(a[L].first, a[L + 1].second));
    return;
  }
  for (int i = L; i < R; ++i)
    b.push_back(pair<int, int>(a[mid].first, a[i].second));
  doit(L, mid);
  doit(mid, R);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d %d", &a[i].first, &a[i].second);
  for (int i = 0; i < n; ++i) b.push_back(a[i]);
  sort(a, a + n);
  doit(0, n);
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  printf("%d\n", ((int)(b).size()));
  for (int i = 0; i < ((int)(b).size()); ++i)
    printf("%d %d\n", b[i].first, b[i].second);
  return 0;
}
