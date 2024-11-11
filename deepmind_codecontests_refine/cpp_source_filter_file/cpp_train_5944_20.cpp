#include <bits/stdc++.h>
using namespace std;
inline unsigned long long int in() {
  unsigned long long int p = 0;
  register char ch = 0;
  while (ch < '0' or ch > '9') {
    ch = getchar();
  }
  while (ch >= '0' and ch <= '9') {
    p = (p << 1) + (p << 3) + ch - '0';
    ch = getchar();
  }
  return p;
}
inline void dukya(unsigned long long int n) {
  unsigned long long int N = n, rev, count_ = 0;
  rev = N;
  if (N == 0) {
    putchar('0');
    putchar('\n');
    return;
  }
  while ((rev % 10) == 0) {
    count_++;
    rev /= 10;
  }
  rev = 0;
  while (N != 0) {
    rev = (rev << 3) + (rev << 1) + N % 10;
    N /= 10;
  }
  while (rev != 0) {
    putchar(rev % 10 + '0');
    rev /= 10;
  }
  while (count_--) putchar('0');
  putchar('\n');
}
int main() {
  long long int n = in();
  vector<long long int> v;
  for (long long int i = 0; i < n; ++i) {
    long long int val = in();
    if (val % 2 == 0)
      v.push_back(val - 1);
    else
      v.push_back(val + 1);
  }
  for (long long int i = 0; i < n; ++i) cout << v[i] << " ";
  cout << endl;
  return 0;
}
