#include <bits/stdc++.h>
using namespace std;
inline void read(int &first) {
  register int c = getchar();
  first = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    first = (first << 1) + (first << 3) + c - 48;
  }
  if (neg) first = -first;
}
inline void read(long long &first) {
  register int c = getchar();
  first = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    first = (first << 1) + (first << 3) + c - 48;
  }
  if (neg) first = -first;
}
inline void writeln(long long first) {
  char buffor[21];
  register int i = 0;
  int neg = 0;
  if (first < 0) {
    neg = 1;
    first = -first;
  }
  do {
    buffor[i++] = (first % 10) + '0';
    first /= 10;
  } while (first);
  i--;
  if (neg) putchar('-');
  while (i >= 0) putchar(buffor[i--]);
  putchar('\n');
}
inline void write(long long first) {
  char buffor[21];
  register int i = 0;
  int neg = 0;
  if (first < 0) {
    neg = 1;
    first = -first;
  }
  do {
    buffor[i++] = (first % 10) + '0';
    first /= 10;
  } while (first);
  i--;
  if (neg) putchar('-');
  while (i >= 0) putchar(buffor[i--]);
  putchar(' ');
}
const int N = 2e3 + 7;
bool cur;
int n, m, l, r;
int a[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++)
      if (a[i] < a[j]) cur ^= 1;
  read(m);
  for (int i = 1; i <= m; i++) {
    read(l);
    read(r);
    int len = (r - l + 1);
    if ((len * (len - 1) / 2) % 2 == 1) cur ^= 1;
    cout << (cur ? "odd\n" : "even\n");
  }
}
