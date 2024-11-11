#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b > 0 ? gcd(b, a % b) : a; }
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
int a[1000005];
int b[1000005];
int main() {
  int n, m, p;
  n = read();
  m = read();
  p = read();
  for (int i = 0; i < n; i++) {
    a[i] = read();
    a[i] = a[i] % p;
  }
  for (int i = 0; i < m; i++) {
    b[i] = read();
    b[i] = b[i] % p;
  }
  int ans = 0;
  int flag = -1;
  int temp = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0 && b[i] == 0 && flag == -1) {
      flag = i;
    }
    if (a[i] != 0) {
      for (int j = i; j < m; j++) {
        if (b[j] != 0) {
          temp = i + j;
          break;
        }
      }
    } else if (b[i] != 0) {
      for (int j = i; j < n; j++) {
        if (a[j] != 0) {
          temp = i + j;
          break;
        }
      }
    }
    if (temp != -1) break;
  }
  if (flag != -1) {
    cout << temp + 2 * flag << endl;
  } else {
    cout << temp << endl;
  }
}
