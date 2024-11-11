#include <bits/stdc++.h>
inline void in(int &MAGNUS) { scanf("%d", &MAGNUS); }
inline void out(int MAGNUS) { printf("%d\n", MAGNUS); }
inline void in(int &MAGNUS, int &CLAR) { scanf("%d%d", &MAGNUS, &CLAR); }
inline void out(int MAGNUS, int CLAR) { printf("%d %d\n", MAGNUS, CLAR); }
inline void inl(long long &LIV) { scanf("%lld", &LIV); }
inline void inl(long long &LIV, long long &MART) {
  scanf("%lld%lld", &LIV, &MART);
}
inline void outl(long long LIV) { printf("%lld\n", LIV); }
inline void outl(long long LIV, long long MART) {
  printf("%lld %lld\n", LIV, MART);
}
using namespace std;
int main() {
  int N;
  in(N);
  puts("YES");
  for (int i = 1; i <= N; i++) {
    int x1, y1, x2, y2;
    in(x1, y1);
    in(x2, y2);
    int x = abs(x1 % 2);
    int y = abs(x2 % 2);
    if (x % 2 == 0 && y % 2 == 0)
      out(1);
    else if (x % 2 == 0 && y % 2 == 1)
      out(2);
    else if (x % 2 == 1 && y % 2 == 0)
      out(3);
    else
      out(4);
  }
  return 0;
}
