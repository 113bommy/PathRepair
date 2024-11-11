#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
typedef double LD;
using namespace std;
const int N = 1000000 + 5;
int n, k;
int f[N];
int f2[N];
void update(int v, int val) {
  for (; v <= n; v += (v & (-v))) f[v] += val;
}
void update2(int v, int val) {
  for (; v <= n; v += (v & (-v))) f2[v] += val;
}
int get(int v) {
  int res = 0;
  for (; v; v -= (v & (-v))) res += f[v];
  return res;
}
int get2(int v) {
  int res = 0;
  for (; v; v -= (v & (-v))) res += f2[v];
  return res;
}
int getval(int s, int f) {
  if (s <= f) return get(f) - get(s - 1);
  return 0;
}
int getval2(int s, int f) {
  if (s <= f) return get2(f) - get2(s - 1);
  return 0;
}
int GET(int cr, int k) {
  int Q = 0;
  int f = min(cr + k - 1, n - k);
  Q += getval(cr + 1, f);
  if (f != cr + k - 1) Q += getval(f + 1, min(cr + k - 1, cr - 1 + k - n));
  Q += getval(max(cr + 1 - k, 1), cr - 1);
  if (cr <= k - 1)
    Q += getval(max(n - k + 1, max(cr + k + 1, cr + 1 + n - k)), n);
  return Q;
}
int GET2(int cr, int k) {
  int Q = 0;
  int f = min(cr + k - 1, n - k);
  Q += getval2(cr + 1, f);
  if (f != cr + k - 1) {
    Q += getval2(f + 1, min(cr + k - 1, cr - 1 + n - k));
  }
  Q += getval2(max(cr + 1 - k, 1), cr - 1);
  if (cr <= k - 1)
    Q += getval2(max(n - k + 1, max(cr + k + 1, cr + 1 + n - k)), n);
  return Q;
}
void solve() {
  scanf("%d%d", &n, &k);
  int cr = 1;
  long long res = 1;
  for (int i = 1; i <= (int)(n); ++i) {
    int Q = 0;
    if (cr + k <= n) {
      Q = GET(cr, k);
    } else {
      Q = GET2(cr + k - n, n - k);
    }
    res += Q + 1;
    printf("%lld ", res);
    update(cr, 1);
    cr += k;
    if (cr > n) cr -= n;
    update2(cr, 1);
  }
  puts("");
}
long long rd() { return ((long long)rand() << 16) + rand(); }
void testgen() {
  FILE* f = fopen("input.txt", "w");
  int n = 1000000;
  fprintf(f, "%d 1000000000\n", n);
  for (int i = 1; i <= (int)(n); ++i)
    fprintf(f, "%d ", rand() % 1000000000 + 1);
  fclose(f);
}
int main() {
  std::cout << std::fixed;
  std::cout.precision(8);
  std::cerr << std::fixed;
  std::cerr.precision(3);
  solve();
  return 0;
}
