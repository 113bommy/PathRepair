#include <bits/stdc++.h>
using namespace std;
inline long long int square(long long int x) { return (x * x); }
int a, b, ans_bla, ans_blb;
long long int ans;
int main() {
  scanf("%d %d", &a, &b);
  if (a == 0) {
    ans = -square(b);
    printf("%lld\n", ans);
    for (int i = 0; i < b; i++) printf("x");
    printf("\n");
    return 0;
  }
  if (a == 1) {
    ans = -square((long long int)(b / 2)) -
          square((long long int)((b + 1) / 2)) + 1;
    ;
    printf("%lld\n", ans);
    for (int i = 0; i < (int)(b / 2); i++) printf("x");
    printf("o");
    for (int i = 0; i < (int)((b + 1) / 2); i++) printf("x");
    printf("\n");
    return 0;
  }
  if (b == 0) {
    ans = square(a);
    printf("%lld\n", ans);
    for (int i = 0; i < a; i++) printf("o");
    printf("\n");
    return 0;
  }
  if (b == 1) {
    ans = square(a) - 1;
    printf("%lld\n", ans);
    for (int i = 0; i < b; i++) printf("o");
    for (int i = 0; i < b; i++) printf("x");
    printf("\n");
    return 0;
  }
  ans = square(a);
  ans -= square((b + 1) / 2) + square(b / 2);
  ans_bla = 1;
  ans_blb = 2;
  for (int bla = 2; bla <= min(a, b - 1); bla++) {
    for (int blb = bla - 1; blb <= bla + 1; blb++) {
      long long int tans = square(a - bla + 1) + bla - 1;
      tans -= square((b / blb) + 1) * (b % blb) +
              square(b / blb) * (blb - (b % blb));
      if (tans > ans) {
        ans = tans;
        ans_bla = bla;
        ans_blb = blb;
      }
    }
  }
  printf("%lld\n", ans);
  if (ans_bla >= ans_blb) {
    for (int i = 0; i < (a - ans_bla + 1); i++) printf("o");
    for (int i = 0; i < (b % ans_blb); i++) {
      for (int j = 0; j < ((int)(b / ans_blb) + 1); j++) printf("x");
      printf("o");
    }
    for (int i = 0; i < (ans_blb - (b % ans_blb)); i++) {
      for (int j = 0; j < (int)(b / ans_blb); j++) printf("x");
      printf("o");
    }
  } else {
    for (int j = 0; j < ((int)(b / ans_blb) + ((b % ans_blb != 0) ? 1 : 0));
         j++)
      printf("x");
    for (int i = 0; i < (a - ans_bla + 1); i++) printf("o");
    for (int i = 1; i < (b % ans_blb); i++) {
      for (int j = 0; j < ((int)(b / ans_blb) + 1); j++) printf("x");
      printf("o");
    }
    for (int i = ((b % ans_blb != 0) ? 0 : 1); i < (ans_blb - (b % ans_blb));
         i++) {
      for (int j = 0; j < (int)(b / ans_blb); j++) printf("x");
      if (i < (ans_blb - (b % ans_blb)) - 1) printf("o");
    }
  }
  printf("\n");
  return 0;
}
