#include <bits/stdc++.h>
const long long MAXLL = 0x7FFFFFFFFFFFFFFFLL;
using namespace std;
const int plus_p[19] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29,
                        31, 37, 41, 43, 47, 53, 59, 30, 42};
const int minus_p[17] = {6,  10, 14, 22, 26, 34, 38, 46, 58,
                         15, 21, 33, 39, 51, 57, 35, 55};
long long POW(long long a, int k) {
  long long res = 1, h = a;
  while (k) {
    if (k & 1) {
      res *= h;
    }
    if (h <= 0 || res <= 0) {
      return MAXLL;
    }
    h *= h;
    k >>= 1;
  }
  return res;
}
long long find_left(long long l, int k) {
  long long left = (long long)ceil(pow(l, 1.0 / k)) + 1;
  while (POW(left - 1, k) >= l) left--;
  return left;
}
long long find_right(long long r, int k) {
  long long right = (long long)floor(pow(r, 1.0 / k)) - 1;
  while (POW(right + 1, k) <= r) right++;
  return right;
}
void SolveCount(long long l, long long r) {
  long long ans = 0;
  if (l == 1) {
    ans++;
    l++;
  }
  for (int i = 0; i < 19; i++) {
    long long left = find_left(l, plus_p[i]);
    long long right = find_right(r, plus_p[i]);
    left <= right ? ans += right - left + 1 : ans;
  }
  for (int i = 0; i < 17; i++) {
    long long left = find_left(l, minus_p[i]);
    long long right = find_right(r, minus_p[i]);
    left <= right ? ans -= right - left + 1 : ans;
  }
  printf("%I64d\n", ans);
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long l, r;
    cin >> l >> r;
    SolveCount(l, r);
  }
}
