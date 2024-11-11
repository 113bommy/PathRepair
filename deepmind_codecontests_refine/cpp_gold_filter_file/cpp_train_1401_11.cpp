#include <bits/stdc++.h>
using namespace std;
const int Maxk = 1e4 + 10;
int Sum = 0;
int n;
int a[Maxk];
inline int read() {
  int s = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
  return f ? -s : s;
}
bool judge(int num) {
  if (num == 1) return false;
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) return false;
  }
  return true;
}
void check(int num) {
  for (int i = 2; i <= num; i++) {
    if (a[i] == 1 && judge(i) && judge(num - i)) {
      a[i] = 2;
      return;
    }
  }
  return;
}
signed main() {
  n = read();
  Sum = n * (n + 1) / 2;
  for (int i = 1; i <= n; i++) a[i] = 1;
  if (judge(Sum)) {
    for (int i = 1; i <= n; i++) cout << 1 << " ";
    return 0;
  }
  if (Sum % 2 == 0) {
    check(Sum);
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
  }
  if (Sum & 1) {
    if (judge(Sum - 2)) {
      a[2] = 2;
    } else {
      Sum -= 3;
      a[3] = 3;
      check(Sum);
    }
  }
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  return 0;
}
