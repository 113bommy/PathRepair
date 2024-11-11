#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
double fRand(double fMin, double fMax) {
  double f = (double)rand() / RAND_MAX;
  return fMin + f * (fMax - fMin);
}
template <class T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <class T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
long long mul(long long a, long long b) {
  if (a * b / a != b) return 1000000000000000007LL;
  return min(1000000000000000007LL, a * b);
}
int prime[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
int n;
bool avail[1 << 9];
vector<int> ans;
int get(int mask) {
  int res = 1;
  for (int i = (0); i <= (8); ++i) {
    if ((mask >> i) & 1) res *= prime[i];
  }
  return res;
}
void mark(int mask) {
  ans.push_back(get(mask));
  avail[mask] = false;
}
int main() {
  scanf("%d", &n);
  if (n == 2) {
    puts("-1");
    return 0;
  }
  memset(avail, true, sizeof avail);
  mark(0b000011111);
  mark(0b111100001);
  mark(0b111110000);
  for (int mask = (0); mask <= ((1 << 9) - 1); ++mask) {
    if ((int)ans.size() == n) break;
    if (__builtin_popcount(mask) == 5 && avail[mask]) mark(mask);
  }
  for (int x : ans) printf("%d\n", x);
  return 0;
}
