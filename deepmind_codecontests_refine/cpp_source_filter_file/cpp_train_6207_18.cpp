#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
#pragma warning(disable : 4786)
using namespace std;
int MIN(int a, int b) { return a < b ? a : b; }
int MAX(int a, int b) { return a > b ? a : b; }
int GCD(int a, int b) {
  while (b) b ^= a ^= b ^= a %= b;
  return a;
}
int LCM(int a, int b) { return a * (b / GCD(a, b)); }
void SWAP(int &a, int &b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}
const double PI = acos(-1);
const double ESP = 1e-11;
int main() {
  int ind, i, j, N, T, result, cnt, counter, temp, temp1, idx, index;
  bool toggle;
  while (scanf("%d", &N) != EOF) {
    if (N == 1) {
      printf("a\na\nb\nb\n");
    } else if (N % 2 == 0) {
      toggle = false;
      for (i = 1; i <= N; i += 2) {
        if (toggle == false) {
          printf("yy");
          toggle = true;
        } else if (toggle == true) {
          printf("zz");
          toggle = false;
        }
      }
      printf("\n");
      toggle = false;
      for (i = 1; i <= N; i += 2) {
        if (toggle == false) {
          printf("cc");
          toggle = true;
        } else if (toggle == true) {
          printf("bb");
          toggle = false;
        }
      }
      printf("\n");
      toggle = false;
      printf("f");
      for (i = 2; i <= N - 2; i += 2) {
        if (toggle == false) {
          printf("ss");
          toggle = true;
        } else if (toggle == true) {
          printf("cc");
          toggle = false;
        }
      }
      printf("k\n");
      toggle = false;
      printf("f");
      for (i = 2; i <= N - 2; i += 2) {
        if (toggle == false) {
          printf("yy");
          toggle = true;
        } else if (toggle == true) {
          printf("zz");
          toggle = false;
        }
      }
      printf("k\n");
    } else {
      toggle = false;
      for (i = 1; i <= N - 1; i += 2) {
        if (toggle == false) {
          printf("aa");
          toggle = true;
        } else if (toggle == true) {
          printf("bb");
          toggle = false;
        }
      }
      printf("m\n");
      toggle = false;
      for (i = 1; i <= N - 1; i += 2) {
        if (toggle == false) {
          printf("ss");
          toggle = true;
        } else if (toggle == true) {
          printf("aa");
          toggle = false;
        }
      }
      printf("m\n");
      toggle = false;
      printf("m");
      for (i = 2; i <= N; i += 2) {
        if (toggle == false) {
          printf("xx");
          toggle = true;
        } else if (toggle == true) {
          printf("yy");
          toggle = false;
        }
      }
      printf("\n");
      toggle = false;
      printf("m");
      for (i = 2; i <= N; i += 2) {
        if (toggle == false) {
          printf("yy");
          toggle = true;
        } else if (toggle == true) {
          printf("xx");
          toggle = false;
        }
      }
      printf("\n");
    }
  }
  return 0;
}
