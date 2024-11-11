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
struct info {
  int x, y, indx;
  bool operator<(const info &p) const {
    if (x / 1000 == p.x / 1000) {
      int res = x / 1000;
      if (res & 1) return y < p.y;
      return p.y < y;
    }
    return x / 1000 < p.x / 1000;
  }
} data[4000000];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i <= n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    data[i].x = a;
    data[i].y = b;
    data[i].indx = i;
  }
  sort(data, data + n);
  for (int i = 0; i <= n - 1; i++) cout << data[i].indx + 1 << " ";
  return 0;
}
