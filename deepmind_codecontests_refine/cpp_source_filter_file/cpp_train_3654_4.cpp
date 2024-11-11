#include <bits/stdc++.h>
using namespace std;
template <class T1>
inline void read(T1 &);
template <class T1>
inline void write(T1);
int s[10005];
int b[10005];
int main() {
  int t;
  read(t);
  while (t--) {
    int n;
    double mini = 100000000000;
    int ansa, ansb;
    read(n);
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= n; i++) {
      int a;
      read(a);
      s[a]++;
    }
    int id = 0;
    for (int i = 1; i <= 10000; i++) {
      if (s[i] >= 2) {
        b[++id] = i;
      }
      if (s[i] >= 4) {
        b[++id] = i;
      }
    }
    for (int i = 1; i < id; i++) {
      double now = (b[i] * 1.0 / b[i - 1]) + (b[i - 1] * 1.0 / b[i]);
      if (now < mini) {
        mini = now;
        ansa = b[i];
        ansb = b[i - 1];
      }
    }
    write(ansa);
    putchar(' ');
    write(ansa);
    putchar(' ');
    write(ansb);
    putchar(' ');
    write(ansb);
    putchar('\n');
  }
  return 0;
}
template <class T1>
void read(T1 &r_e_a_d) {
  T1 k = 0;
  char ch = getchar();
  int flag = 1;
  while (!(ch >= '0' && ch <= '9')) {
    if (ch == '-') {
      flag = -1;
    }
    ch = getchar();
  }
  while ((ch >= '0' && ch <= '9')) {
    k = (k << 1) + (k << 3) + ch - '0';
    ch = getchar();
  }
  r_e_a_d = flag * k;
}
template <class T1>
void write(T1 w_r_i_t_e) {
  if (w_r_i_t_e < 0) {
    putchar('-');
    write(-w_r_i_t_e);
  } else {
    if (w_r_i_t_e < 10) {
      putchar(w_r_i_t_e + '0');
    } else {
      write(w_r_i_t_e / 10);
      putchar((w_r_i_t_e % 10) + '0');
    }
  }
}
