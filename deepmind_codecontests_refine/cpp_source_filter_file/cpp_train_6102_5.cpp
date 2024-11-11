#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c;
  int s = 0, t = 1;
  while (!isdigit(c = getchar()))
    if (c == '-') t = -1;
  do {
    s = s * 10 + c - '0';
  } while (isdigit(c = getchar()));
  return s * t;
}
inline long long readl() {
  char c;
  long long s = 0;
  int t = 1;
  while (!isdigit(c = getchar()))
    if (c == '-') t = -1;
  do {
    s = s * 10 + c - '0';
  } while (isdigit(c = getchar()));
  return s * t;
}
int a[1010];
int main() {
  int n;
  n = read();
  int ans = 0;
  for (int i = 1; i <= n; i++) a[i] = read();
  int c1 = 1;
  a[n + 1] = 1;
  for (int i = 1; i <= n; i++) {
    if (c1 == i && a[i] % 2 == 0) {
      printf("NO");
      return 0;
    }
    if (a[i] % 2 == 1) {
      if ((i - c1 + 1) % 2 == 1 && a[c1 + 1] % 2 == 1) ans++, c1 = i + 1;
    }
  }
  if (a[1] % 2 == 0 || a[n] % 2 == 0 || ans % 2 == 0)
    printf("NO");
  else
    printf("YES");
}
