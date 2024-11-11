#include <bits/stdc++.h>
using namespace std;
long long test, n, a[100010], res;
template <typename T>
inline void read(T& x) {
  char c;
  bool nega = 0;
  while ((!isdigit(c = getchar())) && c != '-')
    ;
  if (c == '-') {
    nega = 1;
    c = getchar();
  }
  x = c - 48;
  while (isdigit(c = getchar())) x = x * 10 + c - 48;
  if (nega) x = -x;
}
int main() {
  read(test);
  while (test--) {
    read(n);
    int i = 1, j = 1;
    while (n > i) {
      n = n - i;
      j++;
      int jjj = j;
      while (jjj) {
        jjj = jjj / 10;
        i++;
      }
    }
    i = 1;
    j = 1;
    while (n > i) {
      n = n - i;
      j++;
      int jjj = j;
      i = 0;
      while (jjj) {
        jjj = jjj / 10;
        i++;
      }
    }
    for (int k = 0; i <= i - n; k++) j = j / 10;
    cout << j % 10 << endl;
  }
}
