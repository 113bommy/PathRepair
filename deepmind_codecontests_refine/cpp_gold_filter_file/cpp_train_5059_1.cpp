#include <bits/stdc++.h>
template <typename T = int>
T next() {
  T result;
  std::cin >> result;
  return result;
}
template <typename T = int, typename C = std::vector<T>>
C nextv(int n) {
  C result(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> result[i];
  }
  return result;
}
template <typename T = int, typename C = std::vector<T>>
C nextv() {
  int n;
  std::cin >> n;
  return nextv(n);
}
struct pairhash {
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U>& x) const {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};
long long compute_gcd(long long a, long long b) {
  if (b == 0) return a;
  return compute_gcd(b, a % b);
}
unsigned long long compute_lcm(unsigned long long a, unsigned long long b) {
  unsigned long long gcd = compute_gcd(a, b);
  return a / gcd * b;
}
int mod_mul(int a, int b, int mod) { return ((long long)a * b) % mod; }
int mod_add(int a, int b, int mod) { return ((long long)a + b) % mod; }
long long choose(int n, int k) {
  if (k == 0 || n == 0) return 1;
  long long result = n * choose(n - 1, k - 1) / k;
  return result;
}
double distance(double point_x, double point_y, double line_x1, double line_y1,
                double line_x2, double line_y2) {
  double nom =
      abs((line_y2 - line_y1) * point_x - (line_x2 - line_x1) * point_y +
          line_x2 * line_y1 - line_y2 * line_x1);
  double denom = sqrt((line_y2 - line_y1) * (line_y2 - line_y1) +
                      (line_x2 - line_x1) * (line_x2 - line_x1));
  return nom / denom;
}
template <typename T>
T sign(T value) {
  if (value > 0) return 1;
  if (value < 0) return -1;
  return 0;
}
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int p = next();
  int x = next();
  int y = next();
  int halfHacks = 0;
  while (x - 50 >= y) {
    x -= 50;
    --halfHacks;
  }
  while (x + 50 <= y) {
    x += 50;
    ++halfHacks;
  }
  int s = x;
  while (true) {
    int i = (s / 50) % 475;
    for (int j = 0; j < 25; ++j) {
      i = (i * 96 + 42) % 475;
      if (p == 26 + i) {
        if (halfHacks < 0)
          cout << 0;
        else
          cout << halfHacks / 2 + halfHacks % 2;
        return 0;
      }
    }
    s += 50;
    ++halfHacks;
  }
}
