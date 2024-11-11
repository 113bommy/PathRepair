#include <bits/stdc++.h>
using namespace std;
template <class T>
bool cmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool cmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
const int N = 64;
int Q;
long long S[N];
int lvl(long long x) { return 63 - __builtin_clzll(x); }
long long where(long long x) {
  int i = lvl(x);
  return (x + S[i]) % (1LL << i);
}
long long who(int i, long long p) {
  p = (p - S[i] + (1LL << i)) % (1LL << i);
  return p + (1LL << i);
}
void shift(int i, long long x) {
  S[i] += x;
  S[i] %= (1LL << i);
}
void print() {
  long long x, p;
  scanf("%lld", &x);
  int i = lvl(x);
  p = (1LL << i) + where(x);
  while (i >= 0) {
    printf("%lld ", who(i, p - (1LL << i)));
    p = p / 2, i--;
  }
  puts("");
}
int main() {
  int qt;
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d", &qt);
    if (qt == 3) {
      print();
    } else {
      long long x, k;
      int i;
      scanf("%lld%lld", &x, &k);
      i = lvl(x);
      k %= (1LL << i);
      k += (1LL << i);
      k %= (1LL << i);
      shift(i, k);
      if (qt == 2) {
        for (i = i + 1; i < N; ++i) {
          k = (k * 2) % (1LL << i);
          shift(i, k);
        }
      }
    }
  }
  return 0;
}
