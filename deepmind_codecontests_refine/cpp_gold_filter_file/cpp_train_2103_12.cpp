#include <bits/stdc++.h>
using namespace std;
template <typename tn>
void read(tn &a) {
  tn x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
  a = x * f;
}
int main() {
  int T;
  read(T);
  while (T--) {
    bool flag = false;
    int a, b, c, d, k;
    read(a), read(c), read(b), read(d), read(k);
    for (int i = 0; i <= k; i++) {
      int j = k - i;
      if (i * b >= a && j * d >= c) {
        cout << i << ' ' << j << '\n';
        flag = true;
        break;
      }
    }
    if (!flag) cout << "-1\n";
  }
  return 0;
}
