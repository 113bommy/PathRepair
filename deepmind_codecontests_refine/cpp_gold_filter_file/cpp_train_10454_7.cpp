#include <bits/stdc++.h>
using namespace std;
long long num12[51], num21[51], num1[51], num2[51], num22[51];
long long x;
long long n, m;
int head[51], tail[51];
void Init() {
  num12[1] = 0;
  num22[1] = 0;
  num21[1] = 0;
  num2[1] = 0;
  num1[1] = 1;
  head[1] = 1;
  tail[1] = 1;
  num12[2] = 0;
  num22[2] = 0;
  num21[2] = 0;
  num2[2] = 1;
  num1[2] = 0;
  head[2] = 2;
  tail[2] = 2;
  for (int i = 3; i <= 50; i++) {
    num1[i] = num1[i - 1] + num1[i - 2];
    num2[i] = num2[i - 1] + num2[i - 2];
    tail[i] = tail[i - 1];
    head[i] = head[i - 2];
    num12[i] =
        num12[i - 1] + num12[i - 2] + (tail[i - 2] == 1 && head[i - 1] == 2);
    num21[i] =
        num21[i - 1] + num21[i - 2] + (tail[i - 2] == 2 && head[i - 1] == 1);
    num22[i] =
        num22[i - 1] + num22[i - 2] + (tail[i - 2] == 2 && head[i - 1] == 2);
  }
}
char ch[3] = {'A', 'C', 'D'};
int main() {
  int n, m, k, x;
  Init();
  bool flag = false;
  cin >> k >> x >> n >> m;
  for (int a1 = 0; a1 < 3; a1++) {
    for (int a2 = 0; a2 < 3; a2++) {
      for (int a3 = 0; a3 < 3; a3++) {
        for (int a4 = 0; a4 < 3; a4++) {
          if (n == 1 && a1 != a2) continue;
          if (m == 1 && a3 != a4) continue;
          long long AC = 0;
          AC += num12[k] * (ch[a2] == 'A' && ch[a3] == 'C');
          AC += num22[k] * (ch[a4] == 'A' && ch[a3] == 'C');
          AC += num21[k] * (ch[a4] == 'A' && ch[a1] == 'C');
          if (AC > x) {
            continue;
          } else {
            int top = 0, bot = 0;
            if (ch[a1] == 'A' && ch[a2] == 'C' && n == 2) bot += 1;
            if (ch[a1] != 'A') {
              if (ch[a2] != 'C') {
                top += (n - 2) / 2;
              } else {
                top += (n - 1) / 2;
              }
            } else {
              if (ch[a2] != 'C') {
                top += (n - 1) / 2;
              } else {
                top += (n) / 2;
              }
            }
            int X = bot, Y = top;
            if (n == 1) X = Y = 0;
            swap(a1, a3);
            swap(a2, a4);
            top = 0, bot = 0;
            if (ch[a1] == 'A' && ch[a2] == 'C' && m == 2) bot += 1;
            if (ch[a1] != 'A') {
              if (ch[a2] != 'C') {
                top += (m - 2) / 2;
              } else {
                top += (m - 1) / 2;
              }
            } else {
              if (ch[a2] != 'C') {
                top += (m - 1) / 2;
              } else {
                top += (m) / 2;
              }
            }
            swap(a1, a3);
            swap(a2, a4);
            if (m == 1) bot = 0, top = 0;
            for (long long i = X; i <= Y; i++) {
              long long Z = x - AC;
              for (long long j = bot; j <= top; j++) {
                if (Z == num1[k] * i + num2[k] * j) {
                  flag = true;
                  long long A1 = i, A2 = j;
                  printf("%c", ch[a1]);
                  bool AF;
                  AF = (ch[a1] == 'A');
                  for (int k = 2; k < n; k++) {
                    if (A1) {
                      if (AF) {
                        A1--;
                        AF = false;
                        printf("%c", 'C');
                      } else {
                        AF = true;
                        printf("%c", 'A');
                      }
                    } else
                      printf("%C", 'D');
                  }
                  if (n != 1)
                    printf("%c\n", ch[a2]);
                  else
                    puts("");
                  AF = (ch[a3] == 'A');
                  printf("%c", ch[a3]);
                  A1 = j;
                  for (int k = 2; k < m; k++) {
                    if (A1) {
                      if (AF) {
                        A1--;
                        AF = false;
                        printf("%c", 'C');
                      } else {
                        AF = true;
                        printf("%c", 'A');
                      }
                    } else
                      printf("%C", 'D');
                  }
                  if (m != 1)
                    printf("%c\n", ch[a4]);
                  else
                    puts("");
                  goto FUCK;
                }
              }
            }
          }
        }
      }
    }
  }
FUCK:;
  if (!flag) puts("Happy new year!");
}
