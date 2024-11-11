#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(const T &a) {
  return a * a;
}
const int max_n = 1000010;
int OR(int a, int b) {
  if (b < a) swap(a, b);
  if (b < 2) {
    return 1 << (a | b);
  }
  if (a == 1) {
    return 1 << 1;
  }
  if (a == 0) {
    return 1 << b;
  }
  return (1 << 1) | (1 << 2);
}
int AND(int a, int b) {
  if (b < a) swap(a, b);
  if (b < 2) {
    return 1 << (a & b);
  }
  if (a == 0) {
    return 1 << 0;
  }
  if (a == 1) {
    return 1 << b;
  }
  return (1 << 0) | (1 << 2);
}
int XOR(int a, int b) {
  if (b < a) swap(a, b);
  if (b < 2) {
    return 1 << (a ^ b);
  }
  if (a == 2) {
    return (1 << 0) | (1 << 1);
  }
  return (1 << 2);
}
struct Mask {
  int mask;
  Mask(int a = 0) { this->mask = 1 << a; }
  bool can(int i) const { return (mask & (1 << i)); }
  void operator|=(const Mask &v) {
    int res = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (can(i) && v.can(j)) {
          res |= OR(i, j);
        }
      }
    }
    mask = res;
  }
  void operator&=(const Mask &v) {
    int res = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (can(i) && v.can(j)) {
          res |= AND(i, j);
        }
      }
    }
    mask = res;
  }
  void operator^=(const Mask &v) {
    int res = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (can(i) && v.can(j)) {
          res |= XOR(i, j);
        }
      }
    }
    mask = res;
  }
};
char s[max_n];
char op[max_n];
Mask v[max_n];
int calc() {
  char *p = s;
  int u = -1, uv = -1;
  for (; *p; p++) {
    switch (*p) {
      case '(':
        break;
      case ')':
        uv--;
        switch (op[u]) {
          case '|':
            v[uv] |= v[uv + 1];
            break;
          case '&':
            v[uv] &= v[uv + 1];
            break;
          case '^':
            v[uv] ^= v[uv + 1];
            break;
        }
        u--;
        break;
      case '?':
        v[++uv] = 2;
        break;
      case '0':
        v[++uv] = 0;
        break;
      case '1':
        v[++uv] = 1;
        break;
      default:
        op[++u] = *p;
    }
  }
  return v[0].mask & (1 << 2);
}
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", &s);
  if (!calc()) {
    printf("NO");
  } else {
    printf("YES");
  }
  return 0;
}
