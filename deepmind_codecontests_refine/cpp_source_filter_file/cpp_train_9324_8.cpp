#include <bits/stdc++.h>
using namespace std;
long long B[100100];
int a[100100], b[100100];
void add(int u, int x) {
  for (; u < 100100; u += u & -u) b[u] += x;
}
void Add(int u, int x) {
  for (; u < 100100; u += u & -u) B[u] += x;
}
long long calc1(int u, long long ans = 0) {
  for (; u; u -= u & -u) ans += B[u];
  return ans;
}
int calc2(int u, int ans = 0) {
  for (; u; u -= u & -u) ans += b[u];
  return ans;
}
int main() {
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long ans = 0;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    ans += (calc1(n) - calc1(a[i])) * (n - i + 1);
    Add(a[i], i);
    cnt += (calc2(n) - calc2(a[i]));
    add(a[i], 1);
  }
  long long p = (long long)n * (n + 1) / 2;
  long double E = cnt - (long double)ans / p;
  for (int i = 1; i <= n; i++) {
    long double t = (long double)i * (i - 1) / 4 * (n - i + 1);
    E += (long double)t / p;
  }
  cout << E << endl;
  return 0;
}
