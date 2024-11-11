#include <bits/stdc++.h>
using namespace std;
static const int INF = 500000000;
template <class T>
void debug(T a, T b) {
  for (; a != b; ++a) cerr << *a << ' ';
  cerr << endl;
}
int n;
int main() {
  cin >> n;
  if (n & 1) {
    puts("-1");
    return 0;
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if ((i >> 1 & 1) ^ (j >> 1 & 1) ^ k)
          putchar('w');
        else
          putchar('b');
      }
      putchar('\n');
    }
    putchar('\n');
  }
  return 0;
}
