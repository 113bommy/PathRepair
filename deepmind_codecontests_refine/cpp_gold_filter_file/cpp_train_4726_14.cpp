#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T lowbit(T x) {
  return x & -x;
}
const int MOD = 1000000007;
const int MAXM = 1000000;
int ta[MAXM + 2], N;
int madd(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  if (a < 0) a += MOD;
  return a;
}
void ins(int x, int v) {
  x++;
  while (x <= MAXM + 1) {
    ta[x] = madd(ta[x], v);
    x += lowbit(x);
  }
}
int find(int x) {
  int v = 0;
  x++;
  while (x > 0) {
    v = madd(v, ta[x]);
    x -= lowbit(x);
  }
  return v;
}
int main(int argc, char *argv[]) {
  cin >> N;
  vector<int> a(N);
  for (int n_ = (N), i = 0; i < n_; ++i) cin >> a[i];
  for (int n_ = (N), i = 0; i < n_; ++i) {
    int d = find(a[i]) - find(a[i] - 1);
    ins(a[i], a[i] * (long long)find(a[i]) % MOD);
    ins(a[i], a[i]);
    ins(a[i], -d);
  }
  cout << find(MAXM) << endl;
  return 0;
}
