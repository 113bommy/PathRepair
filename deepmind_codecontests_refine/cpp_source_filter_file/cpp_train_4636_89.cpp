#include <bits/stdc++.h>
using namespace std;
inline void splay(int &v) {
  v = 0;
  char c = 0;
  int p = 1;
  while (c < '0' || c > '9') {
    if (c == '-') p = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    v = (v << 3) + (v << 1) + c - '0';
    c = getchar();
  }
  v *= p;
}
int main() {
  long long x;
  cin >> x;
  if (x == 1)
    puts("1");
  else
    puts("2");
}
