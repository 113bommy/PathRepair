#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d;
signed main() {
  cin >> a >> b >> c >> d;
  if (!a && !b && !c && d == 1) return puts("YES\n3"), 0;
  if (!a && !b && !d && c == 1) return puts("YES\n2"), 0;
  if (!a && !c && !d && b == 1) return puts("YES\n1"), 0;
  if (!b && !c && !d && a == 1) return puts("YES\n0"), 0;
  if (!a && !b && d == c + 1) {
    puts("YES");
    for (long long i = 1; i <= c; i++) printf("3 2 ");
    return cout << 3, 0;
  }
  if (!c && !d && a == b + 1) {
    puts("YES");
    for (long long i = 1; i <= b; i++) printf("0 1 ");
    return cout << 0, 0;
  }
  if (a > b || d > c) return puts("NO"), 0;
  long long A = a, B = b, C = c, D = d;
  if (b < c) {
    B -= A;
    C -= B;
    D -= C;
    if (D == 0) {
      puts("YES");
      for (long long i = 1; i <= A; i++) printf("0 1 ");
      for (long long i = 1; i <= C; i++) printf("2 3 ");
      for (long long i = 1; i <= B; i++) printf("2 1 ");
      return 0;
    } else if (D == 1) {
      puts("YES");
      if (!B) {
        for (long long i = 1; i <= A; i++) printf("1 0 ");
        cout << 1 << " ";
        for (long long i = 1; i <= C; i++) printf("2 3 ");
        return 0;
      }
      for (long long i = 1; i <= A; i++) printf("1 0 ");
      for (long long i = 1; i <= B; i++) printf("1 2 ");
      for (long long i = 1; i <= C; i++) printf("3 2 ");
      cout << 3;
      return 0;
    } else if (D == -1) {
      puts("YES");
      for (long long i = 1; i <= A; i++) printf("0 1 ");
      for (long long i = 1; i <= B; i++) printf("2 1 ");
      for (long long i = 1; i < C; i++) printf("2 3 ");
      cout << 2;
      return 0;
    }
  } else {
    C -= D;
    B -= C;
    A -= B;
    if (A == 0) {
      puts("YES");
      for (long long i = 1; i <= D; i++) printf("3 2 ");
      for (long long i = 1; i <= B; i++) printf("1 0 ");
      for (long long i = 1; i <= C; i++) printf("1 2 ");
      return 0;
    } else if (A == 1) {
      puts("YES");
      if (!C) {
        for (long long i = 1; i <= D; i++) printf("2 3 ");
        cout << 2 << " ";
        for (long long i = 1; i <= B; i++) printf("1 0 ");
        return 0;
      }
      for (long long i = 1; i <= D; i++) printf("2 3 ");
      for (long long i = 1; i <= C; i++) printf("2 1 ");
      for (long long i = 1; i <= B; i++) printf("0 1 ");
      cout << 0;
      return 0;
    } else if (A == -1) {
      puts("YES");
      for (long long i = 1; i <= D; i++) printf("3 2 ");
      for (long long i = 1; i <= C; i++) printf("1 2 ");
      for (long long i = 1; i <= B; i++) printf("1 0 ");
      cout << 1;
      return 0;
    }
  }
  return puts("NO"), 0;
}
