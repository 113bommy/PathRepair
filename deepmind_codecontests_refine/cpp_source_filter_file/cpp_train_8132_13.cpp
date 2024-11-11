#include <bits/stdc++.h>
template <class T>
inline void read(T &k) {
  k = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    k = k * 10 + c - 48;
    c = getchar();
  }
}
using namespace std;
const int N = 500005;
int n, m, k, s, t;
char c[N];
int main() {
  int T;
  read(T);
  while (T--) {
    read(n);
    read(k);
    s = 1 + (n - 1) * 9;
    s += k - 1;
    cout << s << endl;
  }
}
