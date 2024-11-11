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
long long a[105][105];
struct balchoda {
  int id, r, c;
  long long x;
} q[10005];
int main() {
  int m, n, t, i, TT, j;
  long long temp;
  n = scan_d();
  m = scan_d();
  t = scan_d();
  memset(a, 0, sizeof(a));
  for (i = 0; i < t; i++) {
    q[i].id = scan_d();
    if (q[i].id == 3) {
      j = scan_d();
      q[i].r = j - 1;
      j = scan_d();
      q[i].c = j - 1;
      q[i].x = scan_lld();
    } else {
      j = scan_d();
      q[i].r = j - 1;
    }
  }
  reverse(q, q + t);
  for (TT = 0; TT < t; TT++) {
    if (q[TT].id == 1) {
      temp = a[q[TT].r][0];
      i = 1;
      while (i < m) {
        j = q[TT].r;
        temp += a[j][i];
        a[j][i] = temp - a[j][i];
        temp = temp - a[j][i];
        i++;
      }
      a[q[TT].r][0] = temp;
    } else if (q[TT].id == 2) {
      temp = a[0][q[TT].r];
      i = 1;
      while (i < n) {
        j = q[TT].r;
        temp += a[i][j];
        a[i][j] = temp - a[i][j];
        temp = temp - a[i][j];
        i++;
      }
      a[0][q[TT].r] = temp;
    } else if (q[TT].id == 3)
      a[q[TT].r][q[TT].c] = q[TT].x;
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) printf("%lld ", a[i][j]);
    printf("\n");
  }
  return 0;
}
