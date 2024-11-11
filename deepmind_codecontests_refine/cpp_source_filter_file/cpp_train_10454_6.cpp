#include <bits/stdc++.h>
using namespace std;
void readi(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readll(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readc(char &x) {
  char c;
  while ((c = getchar()) == ' ')
    ;
  x = c;
}
void writes(string s) { puts(s.c_str()); }
void writeln() { writes(""); }
void writei(int x) {
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
void writell(long long x) {
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
long long k, x, n, m, i, j, f[55], l[55], r[55];
int main() {
  cin >> k >> x >> n >> m;
  for (f[1] = 0; f[1] * 2 <= n; f[1]++) {
    for (l[1] = 0; l[1] <= 1 && l[1] + f[1] * 2 <= n; l[1]++) {
      for (r[1] = 0; r[1] <= 1 && l[1] + f[1] * 2 + r[1] <= n; r[1]++) {
        for (f[2] = 0; f[2] * 2 <= m; f[2]++) {
          for (l[2] = 0; l[2] <= 1 && l[2] + f[2] * 2 <= m; l[2]++) {
            for (r[2] = 0; r[2] <= 1 && l[2] + f[2] * 2 + r[2] <= m; r[2]++) {
              for (i = 3; i <= k; i++) {
                f[i] = f[i - 2] + f[i - 1];
                if (r[i - 2] && l[i - 1]) f[i]++;
                l[i] = l[n - 2];
                r[i] = r[i - 1];
              }
              if (f[k] == x) {
                if (l[1]) {
                  cout << 'C';
                  n--;
                }
                while (f[1]) {
                  cout << "AC";
                  n -= 2;
                  f[1]--;
                }
                if (r[1]) n--;
                while (n) {
                  cout << 'B';
                  n--;
                }
                if (r[1]) {
                  cout << 'A';
                }
                cout << endl;
                n = m;
                if (l[2]) {
                  cout << 'C';
                  n--;
                }
                while (f[2]) {
                  cout << "AC";
                  n -= 2;
                  f[2]--;
                }
                if (r[2]) n--;
                while (n) {
                  cout << 'B';
                  n--;
                }
                if (r[2]) {
                  cout << 'A';
                }
                return 0;
              }
            }
          }
        }
      }
    }
  }
  cout << "Happy new year!";
  return 0;
}
