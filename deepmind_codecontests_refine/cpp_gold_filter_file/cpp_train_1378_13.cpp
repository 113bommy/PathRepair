#include <bits/stdc++.h>
const int MaxN = 1e5 + 10;
using namespace std;
template <class T>
inline void read(T &x) {
  T cnt = 0;
  bool opt = false;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') opt = true;
  for (; isdigit(ch); ch = getchar()) cnt = (cnt << 3) + (cnt << 1) + (ch ^ 48);
  x = opt ? -cnt : cnt;
}
int T;
int main() {
  read(T);
  while (T--) {
    int x;
    read(x);
    cout << x - 1 << ' ' << 1 << endl;
  }
  return 0;
}
