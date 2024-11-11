#include <bits/stdc++.h>
using namespace std;
int main() {
  long long u, v;
  scanf("%lld %lld", &u, &v);
  if (u > v) {
    puts("-1");
    return 0;
  }
  if (u == 0LL) {
    if (u == v) {
      puts("0");
    } else if (v & 1LL) {
      puts("-1");
    } else {
      puts("2");
      printf("%lld %lld\n", v / 2LL, v / 2LL);
    }
    return 0;
  }
  if (u == v) {
    puts("1");
    printf("%lld\n", u);
    return 0;
  }
  long long diff = v - u;
  if (diff & 1LL) {
    puts("-1");
  } else {
    long long half = diff / 2LL;
    long long bus = half;
    for (int i = 0; i < 62; i++) {
      if (u & (1LL << i)) bus |= (1LL << i);
    }
    if ((bus ^ half) == u and (bus + half == v)) {
      puts("2");
      printf("%lld %lld\n", half, bus);
    } else {
      puts("3");
      printf("%lld %lld %lld\n", half, half, u);
    }
  }
  return 0;
}
