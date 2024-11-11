#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void gmax(T &a, T b) {
  if (a < b) a = b;
}
int N, X;
int calc(vector<vector<int> > &a, int mask) {
  int ret = 0;
  for (int n_ = (X + 1), i = 0; i < n_; ++i)
    ret += (1u << (i)) & mask ? -a[i][X] : a[i][X];
  for (int n_ = (X), i = 0; i < n_; ++i)
    ret += (bool)((1u << (i)) & mask) ^ (bool)((mask >> X) & 1)
               ? -a[X + i + 1][X]
               : a[X + i + 1][X];
  for (int n_ = (X), j = 0; j < n_; ++j) {
    int t1 = a[X][j] + (((mask >> X) & 1) ? -1 : 1) * a[X][X + 1 + j];
    for (int n_ = (X), i = 0; i < n_; ++i) {
      int t = a[i][j];
      t += a[X + 1 + i][j];
      t += ((1u << (i)) & mask ? -1 : 1) * a[i][X + 1 + j];
      t += (bool)(((1u << (i)) & mask) ^ (bool)((mask >> X) & 1) ? -1 : 1) *
           a[X + i + 1][X + 1 + j];
      t1 += max(t, -t);
    }
    int t2 = -a[X][j] + (((mask >> X) & 1) ? 1 : -1) * a[X][X + 1 + j];
    for (int n_ = (X), i = 0; i < n_; ++i) {
      int t = a[i][j];
      t += -a[X + 1 + i][j];
      t += ((1u << (i)) & mask ? -1 : 1) * a[i][X + 1 + j];
      t += (bool)(((1u << (i)) & mask) ^ (bool)((mask >> X) & 1) ? 1 : -1) *
           a[X + i + 1][X + 1 + j];
      t2 += max(t, -t);
    }
    ret += max(t1, t2);
  }
  return ret;
}
int main(int argc, char *argv[]) {
  cin >> N;
  X = N / 2;
  vector<vector<int> > a(N, vector<int>(N));
  int mx = 0;
  for (int n_ = (N), i = 0; i < n_; ++i)
    for (int n_ = (N), j = 0; j < n_; ++j) cin >> a[i][j], mx += a[i][j];
  for (int n_ = ((1u << (X + 1))), i = 0; i < n_; ++i) gmax(mx, calc(a, i));
  cout << mx << endl;
  return 0;
}
