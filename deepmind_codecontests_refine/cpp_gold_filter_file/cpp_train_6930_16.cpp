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
bool isprime[1000005];
void sieve() {
  memset(isprime, true, sizeof(isprime));
  isprime[1] = 0;
  for (int i = 2; i * i <= 1000000; i++)
    for (int j = i * i; j <= 1000000; j += i) isprime[j] = 0;
}
int main() {
  sieve();
  int x;
  in(x);
  for (int i = 1; i <= 1000; i++) {
    if (!isprime[x * i + 1]) {
      out(i);
      return 0;
    }
  }
  return 0;
}
