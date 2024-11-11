#include <bits/stdc++.h>
using namespace std;
long long calc_a(int a, int k) {
  return ((long long)a - k + 1) * (a - k + 1) + k - 1;
}
long long calc_b(int b, int k) {
  int x = b % k;
  long long ret = 0;
  ret += (long long)x * ((b / k) + 1) * ((b / k) + 1);
  ret += (long long)(k - x) * ((b / k)) * (b / k);
  return ret;
}
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  if (a == 0) {
    printf("%I64d\n", -(long long)b * b);
    for (int i = 0; i < b; i++) printf("%c", 'x');
    printf("\n");
  } else if (b == 0) {
    printf("%I64d\n", (long long)a * a);
    for (int i = 0; i < a; i++) printf("%c", 'o');
    printf("\n");
  } else {
    int min_k = -1, min_val = 0;
    long long ret = 0;
    for (int i = 1; i <= a; i++) {
      if (i - 1 > 0 && i - 1 <= b) {
        long long pos_ret = 0;
        pos_ret = calc_a(a, i);
        pos_ret -= calc_b(b, i - 1);
        if (min_k == -1 || pos_ret > ret) ret = pos_ret, min_k = i, min_val = 0;
      }
      if (i <= b) {
        long long pos_ret = 0;
        pos_ret = calc_a(a, i);
        pos_ret -= calc_b(b, i);
        if (min_k == -1 || pos_ret > ret) ret = pos_ret, min_k = i, min_val = 1;
      }
      if (i + 1 <= b) {
        long long pos_ret = 0;
        pos_ret = calc_a(a, i);
        pos_ret -= calc_b(b, i + 1);
        if (min_k == -1 || pos_ret > ret) ret = pos_ret, min_k = i, min_val = 2;
      }
    }
    printf("%I64d\n", ret);
    int ka = min_k, kb;
    kb = ka + min_val - 1;
    if (min_val == 0 || min_val == 1) {
      for (int i = 0; i < a - ka + 1; i++) printf("o");
      for (int j = 0; j < (b % kb); j++) {
        for (int z = 0; z < (b / kb) + 1; z++) printf("x");
        printf("o");
      }
      for (int j = 0; j < kb - (b % kb); j++) {
        for (int z = 0; z < (b / kb); z++) printf("x");
        if (min_val != 1 || j != (kb - (b % kb) - 1)) printf("o");
      }
    } else if (min_val == 2) {
      bool first = true;
      for (int j = 0; j < (b % kb); j++) {
        for (int z = 0; z < (b / kb) + 1; z++) printf("x");
        if (!first)
          printf("o");
        else {
          for (int i = 0; i < a - ka + 1; i++) printf("o");
          first = false;
        }
      }
      for (int j = 0; j < kb - (b % kb); j++) {
        for (int z = 0; z < (b / kb); z++) printf("x");
        if (!first) {
          if (j != (kb - (b % kb) - 1)) printf("o");
        } else {
          for (int i = 0; i < a - ka + 1; i++) printf("o");
          first = false;
        }
      }
    }
    printf("\n");
  }
  return 0;
}
