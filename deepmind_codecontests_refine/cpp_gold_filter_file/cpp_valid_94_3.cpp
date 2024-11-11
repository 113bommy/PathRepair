#include <bits/stdc++.h>
using namespace std;
const int Buffer_Size = 1 << 10;
char buffer[Buffer_Size], *ihead = buffer + Buffer_Size, *itail = ihead;
char Next_Char() {
  if (ihead == itail) fread(buffer, 1, Buffer_Size, stdin), ihead = buffer;
  return *ihead++;
}
template <typename T>
void read(T &n) {
  T w = 1;
  n = 0;
  char ch = Next_Char();
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = Next_Char();
    n *= w;
  }
  while (isdigit(ch)) {
    n = (n << 3) + (n << 1) + (ch & 15);
    ch = Next_Char();
  }
  n *= w;
}
int t, n;
int A[11], B[11];
int Divide(int x) {
  int len = 0;
  while (x) {
    ++len;
    A[len] = x % 10;
    x /= 10;
  }
  return len;
}
int main() {
  read(t);
  while (t--) {
    read(n);
    int len = Divide(n);
    long long ans = 0;
    for (register int i = (0); i <= ((1 << len) - 1); ++i) {
      if ((i & 1) || ((i >> 1) & 1)) continue;
      memcpy(B, A, sizeof(B));
      bool flag = 1;
      for (register int j = (len); j >= (1); --j)
        if (i & (1 << (j - 1))) {
          if (!B[j]) {
            flag = 0;
            break;
          }
          --B[j], B[j - 2] += 10;
        }
      if (!flag) continue;
      for (register int j = (1); j <= (len); ++j)
        if (B[j] == 19) {
          flag = 0;
          break;
        };
      if (!flag) continue;
      long long res = 1;
      int ok = 0;
      for (register int j = (len); j >= (1); --j) {
        if (B[j] == 0 && !ok)
          continue;
        else {
          ++ok;
          if (B[j] < 10)
            res = res * (long long)(B[j] + 1LL);
          else
            res = res * (long long)(19LL - B[j]);
        }
      }
      ans += res;
    }
    printf("%lld\n", ans - 2LL);
  }
  return 0;
}
