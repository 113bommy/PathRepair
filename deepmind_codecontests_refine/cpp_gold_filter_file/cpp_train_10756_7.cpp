#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void chkmax(T& x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
inline void chkmin(T& x, U y) {
  if (y < x) x = y;
}
long long first[2], A, B;
int main() {
  scanf("%lld%lld%lld%lld", &first[0], &first[1], &A, &B);
  if (first[1] >= first[0] + A && first[1] <= first[0] + B) {
    puts("FIRST");
    printf("%lld\n", first[1]);
    return 0;
  }
  if (A <= 0 && B >= 0) {
    puts("DRAW");
    return 0;
  }
  long long C = A + B;
  if (C < 0) {
    C = -C;
    if (first[1] < first[0]) {
      if ((first[0] - first[1]) % C >= -B && (first[0] - first[1]) % C <= -A) {
        long long d = (first[0] - first[1]) % C;
        puts("FIRST");
        printf("%lld\n", first[0] - d);
      } else if ((first[0] - first[1]) % C == 0) {
        puts("SECOND");
      } else {
        puts("DRAW");
      }
      return 0;
    }
    puts("DRAW");
    return 0;
  }
  if (first[1] < first[0]) {
    puts("DRAW");
    return 0;
  }
  if ((first[1] - first[0]) % C == 0) {
    puts("SECOND");
  } else if ((first[1] - first[0]) % C >= A && (first[1] - first[0]) % C <= B) {
    long long d = (first[1] - first[0]) % C;
    puts("FIRST");
    printf("%lld\n", first[0] + d);
  } else {
    puts("DRAW");
  }
  return 0;
}
