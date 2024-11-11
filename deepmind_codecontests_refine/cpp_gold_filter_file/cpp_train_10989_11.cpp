#include <bits/stdc++.h>
using namespace std;
long long f[105], n;
inline long long Read() {
  long long t = 0;
  char c = getchar();
  for (; c > 57 || c < 48; c = getchar())
    ;
  for (; c > 47 && c < 58; c = getchar()) t = (t << 1) + (t << 3) + c - 48;
  return t;
}
int main() {
  n = Read();
  f[1] = 2, f[2] = 3;
  for (int i = 3; i < 105; i++) f[i] = f[i - 1] + f[i - 2];
  for (int i = 1; i < 105; i++)
    if (f[i] > n) {
      cout << i - 1 << endl;
      break;
    }
}
