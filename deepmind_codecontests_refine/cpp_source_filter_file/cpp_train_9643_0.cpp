#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
stringstream output;
inline void eOP();
using namespace std;
template <typename N>
inline N euclideanAlgorithm(N a, N b);
template <typename N>
inline N euclideanAlgorithm(N a, N b, N& x, N& y);
template <typename N>
inline N lcm(N a, N b);
inline size_t reverseBits(size_t n);
template <typename N>
inline N euclideanAlgorithm(N a, N b) {
  while (a != N(0)) {
    b %= a;
    swap(a, b);
  }
  return b;
}
template <typename N>
inline N euclideanAlgorithm(N a, N b, N& x, N& y) {
  N l[3] = {a, 1, 0};
  N r[3] = {b, 0, 1};
  while (l[0] != 0) {
    N n = r[0] / l[0];
    for (int i = 0; i < 3; ++i) {
      r[i] -= l[i] * n;
      swap(l[i], r[i]);
    }
  }
  x = r[1];
  y = r[2];
  return r[0];
}
template <typename N>
inline N lcm(N a, N b) {
  return a / euclideanAlgorithm(a, b) * b;
}
inline size_t reverseBits(size_t x) {
  unsigned int tmp1 = (x & 0xAAAAAAAA) >> 1;
  unsigned int tmp2 = (x & 0x55555555) << 1;
  size_t n = tmp1 | tmp2;
  tmp1 = (n & 0xCCCCCCCC) >> 2;
  tmp2 = (n & 0x33333333) << 2;
  n = tmp1 | tmp2;
  tmp1 = (n & 0xF0F0F0F0) >> 4;
  tmp2 = (n & 0x0F0F0F0F) << 4;
  n = tmp1 | tmp2;
  tmp1 = (n & 0xFF00FF00) >> 8;
  tmp2 = (n & 0x00FF00FF) << 8;
  n = tmp1 | tmp2;
  tmp1 = (n & 0xFFFF0000) >> 16;
  tmp2 = (n & 0x0000FFFF) << 16;
  n = tmp1 | tmp2;
  return n;
}
int main() {
  int n;
  cin >> n;
  int* a = new int[n];
  int one = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] == 1) {
      ++one;
    }
  }
  if (one) {
    output << n - one;
    eOP();
  }
  int g = 0;
  for (int i = 0; i < n; ++i) {
    g = euclideanAlgorithm(g, a[i]);
  }
  if (g != 1) {
    output << -1;
    eOP();
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j + i <= n; ++j) {
      a[j - 1] = euclideanAlgorithm(a[j - 1], a[j]);
      if (a[j - 1] == 1) {
        output << n + i - 1;
        eOP();
      }
    }
  }
  eOP();
}
inline void eOP() {
  cout << output.str();
  output.str(string());
  exit(0);
}
