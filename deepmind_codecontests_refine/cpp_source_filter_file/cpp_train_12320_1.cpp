#include <bits/stdc++.h>
using namespace std;
template <class T>
inline int cMin(T& a, T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
inline int cMax(T& a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
inline string to_str(T v) {
  ostringstream os;
  os << v;
  return os.str();
}
const double pi = acos(-1.0);
const double eps = 1e-9;
template <class T>
inline T isqr(T v) {
  return v * v;
}
template <class T>
inline T iabs(T v) {
  return v < 0 ? -v : v;
}
template <class T>
inline int isgn(T v) {
  return iabs(v) <= eps ? 0 : (v < 0 ? -1 : 1);
}
template <typename T>
inline T next() {
  static char buf[64];
  scanf("%s", buf);
  istringstream is(buf);
  T v;
  is >> v;
  return v;
}
inline int nextInt() {
  int v = 0;
  scanf("%d", &v);
  return v;
}
const int NN = 2 * 100000 + 16;
int N, A[NN], B[NN];
int idx[NN], mm[NN];
int main(int argc, char* argv[]) {
  scanf("%d", &N);
  for (int i = 0; i < (int)(N); ++i) scanf("%d", A + i);
  for (int i = 0; i < (int)(N); ++i) scanf("%d", B + i);
  for (int i = 0; i < (int)(N); ++i) idx[B[i]] = i;
  int n = 0;
  for (int i = 1; i < N; ++i) {
    if (idx[A[i - 1]] > idx[A[i]]) {
      n = i;
      break;
    }
  }
  printf("%d\n", N - n);
  return 0;
}
