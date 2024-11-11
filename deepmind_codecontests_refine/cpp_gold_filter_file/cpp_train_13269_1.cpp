#include <bits/stdc++.h>
using namespace std;
template <typename T>
T next_int() {
  T p = 1, x = 0;
  char ch;
  do {
    ch = getchar();
  } while (ch <= ' ');
  if (ch == '-') {
    p = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return p * x;
}
const int max_n = (int)1e5 + 228;
const int max_int = (int)1e9 + 228;
int a[max_n];
int b[max_n];
int main() {
  int n = next_int<int>();
  for (int i = 0; i < n; i++) {
    a[i] = next_int<int>();
    b[a[i]]++;
    a[i] = b[a[i]];
  }
  bool ok = 1;
  for (int i = 2; i < max_n; i++) {
    if (b[i] > b[i - 1]) ok = 0;
  }
  if (ok == 0) {
    puts("-1");
    return 0;
  }
  cout << b[1] << "\n";
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  puts("");
}
