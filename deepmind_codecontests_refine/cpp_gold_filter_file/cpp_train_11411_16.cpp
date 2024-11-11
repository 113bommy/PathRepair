#include <bits/stdc++.h>
using namespace std;
bool debug = true;
const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
const int dy[] = {1, 0, -1, 0, -1, 1, 1, -1, 0};
template <typename X>
inline X square(const X& a) {
  return a * a;
}
int scan_d() {
  bool minus = false;
  int result = 0;
  char ch;
  ch = getchar();
  while (true) {
    if (ch == '-') break;
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }
  if (ch == '-')
    minus = true;
  else
    result = ch - '0';
  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = (result << 3) + (result << 1) + (ch - '0');
  }
  if (minus)
    return -result;
  else
    return result;
}
long scan_ld() {
  bool minus = false;
  long result = 0;
  char ch;
  ch = getchar();
  while (true) {
    if (ch == '-') break;
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }
  if (ch == '-')
    minus = true;
  else
    result = ch - '0';
  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = (result << 3) + (result << 1) + (ch - '0');
  }
  if (minus)
    return -result;
  else
    return result;
}
long long scan_lld() {
  bool minus = false;
  long long result = 0;
  char ch;
  ch = getchar();
  while (true) {
    if (ch == '-') break;
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }
  if (ch == '-')
    minus = true;
  else
    result = ch - '0';
  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = (result << 3) + (result << 1) + (ch - '0');
  }
  if (minus)
    return -result;
  else
    return result;
}
long long unsigned scan_llu() {
  long long unsigned result = 0;
  char ch;
  ch = getchar();
  while (true) {
    if (ch == '-') break;
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }
  result = ch - '0';
  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = (result << 3) + (result << 1) + (ch - '0');
  }
  return result;
}
void print_d(int n) {
  if (n < 0) {
    n = -n;
    putchar('-');
  }
  int i = 10;
  char output_buffer[10];
  do {
    output_buffer[--i] = (n % 10) + '0';
    n /= 10;
  } while (n);
  do {
    putchar(output_buffer[i]);
  } while (++i < 10);
}
void print_ld(long n) {
  if (n < 0) {
    n = -n;
    putchar('-');
  }
  int i = 11;
  char output_buffer[11];
  do {
    output_buffer[--i] = (n % 10) + '0';
    n /= 10;
  } while (n);
  do {
    putchar(output_buffer[i]);
  } while (++i < 11);
}
void print_lld(long long n) {
  if (n < 0) {
    n = -n;
    putchar('-');
  }
  int i = 21;
  char output_buffer[21];
  do {
    output_buffer[--i] = (n % 10) + '0';
    n /= 10;
  } while (n);
  do {
    putchar(output_buffer[i]);
  } while (++i < 21);
}
void print_llu(long long unsigned n) {
  int i = 21;
  char output_buffer[21];
  do {
    output_buffer[--i] = (n % 10) + '0';
    n /= 10;
  } while (n);
  do {
    putchar(output_buffer[i]);
  } while (++i < 21);
}
void println_d(int n) {
  if (n < 0) {
    n = -n;
    putchar('-');
  }
  int i = 10;
  char output_buffer[11];
  output_buffer[10] = '\n';
  do {
    output_buffer[--i] = (n % 10) + '0';
    n /= 10;
  } while (n);
  do {
    putchar(output_buffer[i]);
  } while (++i < 11);
}
void println_ld(long n) {
  if (n < 0) {
    n = -n;
    putchar('-');
  }
  int i = 11;
  char output_buffer[12];
  output_buffer[11] = '\n';
  do {
    output_buffer[--i] = (n % 10) + '0';
    n /= 10;
  } while (n);
  do {
    putchar(output_buffer[i]);
  } while (++i < 12);
}
void println_lld(long long n) {
  if (n < 0) {
    n = -n;
    putchar('-');
  }
  int i = 21;
  char output_buffer[22];
  output_buffer[21] = '\n';
  do {
    output_buffer[--i] = (n % 10) + '0';
    n /= 10;
  } while (n);
  do {
    putchar(output_buffer[i]);
  } while (++i < 22);
}
void println_llu(long long unsigned n) {
  int i = 21;
  char output_buffer[22];
  output_buffer[21] = '\n';
  do {
    output_buffer[--i] = (n % 10) + '0';
    n /= 10;
  } while (n);
  do {
    putchar(output_buffer[i]);
  } while (++i < 22);
}
char sp;
void printsp_d(int n) {
  if (n < 0) {
    n = -n;
    putchar('-');
  }
  int i = 10;
  char output_buffer[11];
  output_buffer[10] = sp;
  do {
    output_buffer[--i] = (n % 10) + '0';
    n /= 10;
  } while (n);
  do {
    putchar(output_buffer[i]);
  } while (++i < 11);
}
void printsp_ld(long n) {
  if (n < 0) {
    n = -n;
    putchar('-');
  }
  int i = 11;
  char output_buffer[12];
  output_buffer[11] = sp;
  do {
    output_buffer[--i] = (n % 10) + '0';
    n /= 10;
  } while (n);
  do {
    putchar(output_buffer[i]);
  } while (++i < 12);
}
void printsp_lld(long long n) {
  if (n < 0) {
    n = -n;
    putchar('-');
  }
  int i = 21;
  char output_buffer[22];
  output_buffer[21] = sp;
  do {
    output_buffer[--i] = (n % 10) + '0';
    n /= 10;
  } while (n);
  do {
    putchar(output_buffer[i]);
  } while (++i < 22);
}
void printsp_llu(long long unsigned n) {
  int i = 21;
  char output_buffer[22];
  output_buffer[21] = sp;
  do {
    output_buffer[--i] = (n % 10) + '0';
    n /= 10;
  } while (n);
  do {
    putchar(output_buffer[i]);
  } while (++i < 22);
}
long long cal[100005][15], dp[105][105][15];
vector<pair<int, int> > ind;
int main() {
  int n, q, c, j, i, x, y, x1, x2, y1, y2, t;
  long long ans = 0;
  n = scan_d();
  q = scan_d();
  c = scan_d();
  for (i = 0; i < n; i++) {
    x = scan_d();
    y = scan_d();
    t = scan_d();
    cal[i][0] = t;
    dp[x][y][0] += t;
    ind.push_back(make_pair(x, y));
  }
  for (i = 1; i <= c + 3; i++) {
    for (j = 0; j < n; j++) {
      cal[j][i] = (cal[j][i - 1] + 1) % (c + 1);
      dp[ind[j].first][ind[j].second][i] += (cal[j][i]);
    }
  }
  for (t = 0; t <= c + 3; t++) {
    for (i = 1; i <= 100; i++) {
      for (j = 1; j <= 100; j++) {
        dp[i][j][t] += dp[i][j - 1][t];
      }
    }
  }
  while (q--) {
    ans = 0;
    t = scan_d();
    x1 = scan_d();
    y1 = scan_d();
    x2 = scan_d();
    y2 = scan_d();
    if (y1 > y2) swap(y1, y2);
    if (x1 > x2) swap(x1, x2);
    t %= (c + 1);
    for (i = x1; i <= x2; i++) {
      ans += (dp[i][y2][t] - dp[i][y1 - 1][t]);
    }
    println_lld(ans);
  }
  return 0;
}
