#include <bits/stdc++.h>
using namespace std;
class SignedReader {
  char arr[262144];
  char *p, *e;
  int s, val;
  bool neg;
  void getTok() {
    p = arr;
    s = fread(arr, 1, 262144, stdin);
    e = arr + s;
  }
  void skip() {
    while (true) {
      if (p == e) getTok();
      if (*p == '-' || ((*p) >= '0' && (*p) <= '9')) return;
      p++;
    }
  }

 public:
  SignedReader() { getTok(); }
  int nextInt() {
    neg = false;
    skip();
    if (*p == '-') neg = true, p++;
    val = 0;
    while (true) {
      if (p == e) getTok();
      if (p == e) break;
      if (((*p) >= '0' && (*p) <= '9'))
        val = 10 * val + *p - 48, p++;
      else
        break;
    }
    if (neg) val = -val;
    return val;
  }
};
int main() {
  int sh, sm, eh, em, slh, slm;
  scanf("%d:%d\n%d:%d", &sh, &sm, &slh, &slm);
  em = sm - slm;
  if (em < 0) {
    em += 60;
    sh++;
  }
  eh = (sh - slh + 48) % 24;
  if (eh < 10) putchar('0');
  printf("%d:", eh);
  if (em < 10) putchar('0');
  printf("%d\n", em);
  return 0;
}
