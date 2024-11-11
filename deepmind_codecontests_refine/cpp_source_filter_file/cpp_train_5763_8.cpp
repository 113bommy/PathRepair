#include <bits/stdc++.h>
using namespace std;
const int INF = 1000 * 1000 * 1000 + 7;
const double EPS = 1e-9;
int bit_count(int first) {
  return first == 0 ? 0 : 1 + bit_count(first & (first - 1));
}
inline int low_bit(int first) { return first & -first; }
inline int sign(double first) {
  return first < -EPS ? -1 : first > EPS ? 1 : 0;
}
inline int sign(int first) { return (first > 0) - (first < 0); }
template <class T>
void chmin(T &t, T f) {
  if (t > f) t = f;
}
template <class T>
void chmax(T &t, T f) {
  if (t < f) t = f;
}
inline int getint() {
  int a;
  return scanf("%d", &a) ? a : (fprintf(stderr, "trying to read\n"), -1);
}
inline double getdouble() {
  double a;
  return scanf("%lf", &a) ? a : (fprintf(stderr, "trying to read\n"), -1.0);
}
inline double myrand() {
  return ((double)rand() / RAND_MAX) + ((double)rand() / RAND_MAX / RAND_MAX);
}
const int N = 1000;
long long a[N][N], sumrow[N], sumcol[N];
void myCode() {
  int m = getint(), n = getint();
  for (int i = (int)0; i < (int)m; ++i)
    for (int j = (int)0; j < (int)n; ++j) {
      a[i][j] = getint();
      sumrow[i] += a[i][j];
      sumcol[j] += a[i][j];
    }
  int bi = 0, bj = 0;
  long long mi = (long long)2e12, mj = (long long)2e12;
  for (int i = (int)0; i < (int)m + 1; ++i) {
    long long sum = 0;
    for (int k = (int)0; k < (int)m; ++k)
      sum += (((4 * i) - (4 * k + 2)) * ((4 * i) - (4 * k + 2))) * sumrow[k];
    if (sum < mi) {
      mi = sum;
      bi = i;
    }
  }
  for (int j = (int)0; j < (int)n + 1; ++j) {
    long long sum = 0;
    for (int k = (int)0; k < (int)n; ++k)
      sum += (((4 * j) - (4 * k + 2)) * ((4 * j) - (4 * k + 2))) * sumcol[k];
    if (sum < mj) {
      mj = sum;
      bj = j;
    }
  }
  cout << mi + mj << endl << bi << " " << bj << endl;
}
int main() {
  srand(time(NULL));
  myCode();
  return 0;
}
