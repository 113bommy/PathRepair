#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int MaxN = int(2e5) + 256;
const int MOD = int(1e9) + 7;
template <typename T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
inline bool Palindrome(const string& s) {
  return equal(s.begin(), s.end(), s.rbegin());
}
int s[MaxN], a[MaxN];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  for (int i = n - 1; i >= 0; --i) s[i] = max(s[i + 1], a[i]);
  for (int i = 0; i < n; ++i) {
    if (s[i] <= a[i]) {
      printf("0 ");
    } else {
      printf("%d ", abs(s[i] - a[i] + 1));
    }
  }
  return 0;
}
