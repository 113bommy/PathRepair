#include <bits/stdc++.h>
template <class T>
T gcd(T a, T b) {
  T r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T cube(T x) {
  return x * x * x;
}
using namespace std;
long long n, m, a[100005], b;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long sum = 0, cnt = 1;
  for (int i = 1; i <= m; i++) {
    cin >> b;
    while (sum + a[cnt] < b) sum += a[cnt++];
    cout << cnt << " " << b - sum << endl;
  }
}
