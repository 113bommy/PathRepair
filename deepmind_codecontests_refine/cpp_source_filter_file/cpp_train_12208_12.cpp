#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
template <class T>
void read(T &x) {
  T res = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    res = res * 10 + ch - '0';
    ch = getchar();
  }
  x = res * f;
}
int n;
long long sum, a[N], s[N];
int main() {
  read(n);
  for (int i = 0; i < n; i++) {
    read(a[i]);
    sum += a[i] - i;
    s[i] = a[0] + i;
  }
  for (int i = 0; i < n; i++) s[i] += sum / n;
  for (int i = 0; i < sum % n; i++) s[i]++;
  for (int i = 0; i < n; i++) {
    printf("%d ", s[i]);
  }
  printf("\n");
  return 0;
}
