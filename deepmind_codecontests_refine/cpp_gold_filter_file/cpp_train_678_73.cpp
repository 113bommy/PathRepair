#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;
const int MOD = 1000000007;
template <typename tn>
inline tn read() {
  char ch;
  tn f = 1;
  while (!isdigit(ch = getchar()))
    if (ch == '-') f = -1;
  tn x = ch - '0';
  while (isdigit(ch = getchar())) x = x * 10 + ch - '0';
  return x * f;
}
template <typename tn>
inline void cmax(tn &a, tn b) {
  if (a < b) a = b;
}
template <typename tn>
inline void cmin(tn &a, tn b) {
  if (a > b) a = b;
}
int main() {
  int n = read<int>();
  cout << (n + 1) / 2 << endl;
}
