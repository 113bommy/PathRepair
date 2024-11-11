#include <bits/stdc++.h>
using namespace std;
int N, U, R;
int a[32], b[32], k[32], p[32];
long long res = -1e18;
void scan(int t[]) {
  for (int i = 0; i < N; ++i) cin >> t[i];
}
void scan() {
  cin >> N >> U >> R;
  scan(a);
  scan(b);
  scan(k);
  scan(p);
}
void check() {
  long long sum = 0;
  for (int i = 0; i < N; ++i) sum += ((long long)k[i] * (long long)a[i]);
  if (res < sum) res = sum;
}
void gen(int oper, int last) {
  if ((U - oper) % 2 == 0) check();
  if (oper == U) return;
  int t[32];
  memcpy(t, a, sizeof(t));
  for (int i = 0; i < N; ++i) a[i] = t[p[i] - 1] + R;
  gen(oper + 1, 1);
  memcpy(a, t, sizeof(a));
  if (last) {
    for (int i = 0; i < N; ++i) a[i] ^= b[i];
    gen(oper + 1, 0);
    for (int i = 0; i < N; ++i) a[i] ^= b[i];
  }
}
void solve() {
  gen(0, 1);
  cout << res << endl;
}
int main() {
  scan();
  solve();
}
