#include <bits/stdc++.h>
using namespace std;
template <class T>
T Bitcnt(T a) {
  int sum = 0;
  while (a) {
    if (a & 1) sum++;
    a /= 2;
  }
  return sum;
}
template <class T>
T Max3(T a, T b, T c) {
  return max(a, max(b, c));
}
template <class T>
T Lcm(T a, T b) {
  T tmp = __gcd(a, b);
  return (a / tmp) * b;
}
template <class T>
T Pow(T a, T b) {
  T ans = 1;
  T base = a;
  while (b) {
    if (b & 1) ans = (ans * base);
    base = (base * base);
    b /= 2;
  }
  return ans;
}
long long Bigmod(long long a, long long b) {
  long long res = 1;
  long long pw = a % 1000000007LL;
  while (b > 0) {
    if (b & 1) res = (res * pw) % 1000000007LL;
    pw = (pw * pw) % 1000000007LL;
    b /= 2;
  }
  return res;
}
int a_x[] = {1, -1, 0, 0};
int a_y[] = {0, 0, 1, -1};
long long X, Y;
void extend_euclid(long long a, long long b) {
  if (b == 0) {
    X = a;
    Y = 0;
    return;
  }
  extend_euclid(b, a % b);
  long long x, y;
  x = Y;
  y = X - (a / b) * Y;
  X = x;
  Y = y;
}
long long inverse_modulo(long long a, long long b) {
  extend_euclid(a, b);
  return (X + 1000000007LL) % 1000000007LL;
}
int x[4000000], y[4000000];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%d %d", &x[0], &y[0]);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }
  int ok = 0;
  if (x[0] < x[n - 1]) ok = 1;
  int ans = 0;
  for (int i = 2; i <= n; i++) {
    int prev = i - 1;
    int next = (i + 1);
    if (next > n) next = 2;
    if (ok) {
      if (x[prev] < x[i] && y[i] < y[next])
        ans++;
      else if (y[prev] < y[i] && x[next] < x[i])
        ans++;
      else if (y[i] > y[next] && x[i] < x[prev])
        ans++;
      else if (x[i] < x[next] && y[i] < y[prev])
        ans++;
    } else {
      if (y[prev] < y[i] && x[next] > x[i])
        ans++;
      else if (x[prev] < x[i] && y[i] > y[next])
        ans++;
      else if (y[i] < y[next] && x[i] < x[prev])
        ans++;
      else if (x[i] > x[next] && y[i] < y[prev])
        ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
