#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
int biton(int N, int pos) { return N = N | (1 << pos); }
int bitoff(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
long long int ipow(long long int base, long long int exp) {
  long long int result = 1;
  while (exp) {
    if (exp & 1) result = 1LL * result * base;
    exp >>= 1;
    base = 1LL * base * base;
  }
  return result;
}
long long int n, k;
int main() {
  ;
  cin >> k >> n;
  long long int h = ceil(log2(n));
  long long int l = (log2(n));
  long long int hi = ipow(2, h);
  long long int lo = ipow(2, l);
  l++, h++;
  ;
  if (lo == hi) return printf("%lli\n", l), 0;
  while (lo < hi) {
    ;
    long long int mid = lo + (hi - lo) / 2;
    if (n > mid) {
      lo = mid + 1;
      l = min(l, h) - 1;
    } else {
      hi = mid;
      h = min(l, h) - 1;
    }
  }
  printf("%lli\n", h);
}
