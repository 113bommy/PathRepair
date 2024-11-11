#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
inline int add(int a, int b) {
  a += b;
  return a >= 1000000007 ? a - 1000000007 : a;
}
inline int sub(int a, int b) {
  a -= b;
  return a < 0 ? a + 1000000007 : a;
}
inline int mul(int a, int b) { return (long long int)a * b % 1000000007; }
int Set(int N, int pos) { return N = N | (1 << pos); }
int Reset(int N, int pos) { return N = N & ~(1 << pos); }
bool Cheek(int N, int pos) { return (bool)(N & (1 << pos)); }
int a[100005], b[100005], lft[100005], rgt[100005], addina[100005];
void Solve(int t) {
  int i, j, k, n, ans = 0;
  scanf("%d", &(n));
  for (__typeof(i) i = 1; i <= n; i++) {
    scanf("%d", &(a[i]));
    addina[a[i]] = i;
  }
  for (__typeof(i) i = 1; i <= n; i++) scanf("%d", &(b[i]));
  for (i = 1; i <= n; i++) {
    int address = addina[b[i]];
    int needlft = (n - address + i) % n;
    lft[needlft]++;
    int needrgt = (address - i + n) % n;
    rgt[needrgt]++;
  }
  for (i = 1; i <= n; i++) {
    ans = max(ans, lft[i]);
    ans = max(ans, rgt[i]);
  }
  cout << ans << endl;
}
int main() {
  int t, T;
  T = 1;
  for (__typeof(t) t = 1; t <= T; t++) {
    Solve(t);
  }
  return 0;
}
