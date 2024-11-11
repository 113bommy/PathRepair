#include <bits/stdc++.h>
using namespace std;
long long Cs[65][65];
long long C(int n, int k) {
  if (k < 0) return 0;
  if (k == 0) return 1;
  if (n == 0) return 0;
  if (Cs[n][k] == -1) {
    Cs[n][k] = C(n - 1, k - 1) + C(n - 1, k);
  }
  return Cs[n][k];
}
unsigned long long F(unsigned long long x, int k) {
  int count = 0;
  unsigned long long result = 0;
  int pos = 63;
  for (; pos >= 0; --pos) {
    if (((1ULL << pos) & x) != 0) {
      if (count <= k && k - count <= pos) result += C(pos, k - count);
      ++count;
    }
  }
  if (count == k) ++result;
  return result;
}
int main() {
  for (int i = 0; i < 65; ++i)
    for (int j = 0; j < 65; ++j) Cs[i][j] = -1;
  unsigned long long m, k;
  cin >> m >> k;
  unsigned long long left = 0,
                     right = std::numeric_limits<unsigned long long>::max() >>
                             1 - 1;
  while (left < right) {
    unsigned long long middle = left + ((right - left) >> 1);
    if (F(middle << 1, k) - F(middle, k) < m)
      left = middle + 1;
    else
      right = middle;
  }
  cout << left << endl;
  return 0;
}
