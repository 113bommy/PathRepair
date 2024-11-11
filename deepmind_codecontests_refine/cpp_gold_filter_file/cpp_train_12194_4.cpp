#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void amin(T &x, const T &y) {
  if (y < x) x = y;
}
template <class T>
inline void amax(T &x, const T &y) {
  if (x < y) x = y;
}
template <class Iter>
void rprintf(const char *fmt, Iter begin, Iter end) {
  for (bool sp = 0; begin != end; ++begin) {
    if (sp)
      putchar(' ');
    else
      sp = true;
    printf(fmt, *begin);
  }
  putchar('\n');
}
int N, Q;
string ans;
const int SIZE = 110 * 64;
using Bits = bitset<SIZE>;
Bits B[100001];
Bits Mask[SIZE + 1];
bool prime[SIZE + 1];
bool mu[SIZE + 1];
void init() {
  for (int i = 2; i < SIZE; i++) prime[i] = true;
  for (int i = 2; i < SIZE; i++)
    if (prime[i]) {
      for (int j = i * i; j < SIZE; j += i) {
        prime[j] = false;
      }
    }
  for (int i = 1; i < SIZE; i++) mu[i] = true;
  for (int i = 2; i < SIZE; i++)
    if (prime[i]) {
      for (int j = i * i; j < SIZE; j += i * i) mu[j] = false;
    }
  for (int i = 1; i < SIZE; i++) {
    for (int t = 1; i * t < SIZE; t++)
      if (mu[t]) {
        Mask[i].set(i * t);
      }
  }
}
void OP1() {
  int x, v;
  scanf("%d%d", &x, &v);
  B[x].reset();
  for (int i = 1; i * i <= v; i++) {
    if (v % i == 0) {
      B[x].set(i);
      if (i * i < v) {
        B[x].set(v / i);
      }
    }
  }
}
void OP2() {
  int x, y, z;
  scanf("%d%d%d", &x, &y, &z);
  B[x] = B[y] ^ B[z];
}
void OP3() {
  int x, y, z;
  scanf("%d%d%d", &x, &y, &z);
  B[x] = B[y] & B[z];
}
void OP4() {
  int x, v;
  scanf("%d%d", &x, &v);
  int t = (B[x] & Mask[v]).count();
  ans.push_back(t % 2 + '0');
}
void MAIN() {
  scanf("%d%d", &N, &Q);
  for (int i = 0, i_len = (N + 1); i < i_len; ++i) B[i].reset();
  for (int $ = 0, $_len = (Q); $ < $_len; ++$) {
    char op[11];
    scanf("%s", op);
    if (*op == '1') {
      OP1();
    } else if (*op == '2') {
      OP2();
    } else if (*op == '3') {
      OP3();
    } else if (*op == '4') {
      OP4();
    }
  }
  puts(ans.c_str());
}
int main() {
  init();
  int TC = 1;
  for (int tc = 0, tc_len = (TC); tc < tc_len; ++tc) MAIN();
  return 0;
}
