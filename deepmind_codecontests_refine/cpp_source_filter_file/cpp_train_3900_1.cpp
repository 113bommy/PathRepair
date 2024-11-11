#include <bits/stdc++.h>
using namespace std;
inline void print(char pt) { printf("%c\n", pt); }
inline void print(int pt) { printf("%d\n", pt); }
inline void print(long long pt) { printf("%I64d\n", pt); }
inline void print(double pt) { printf("%.20f\n", pt); }
inline void print(char pt[]) { printf("%s\n", pt); }
inline void print() { printf("\n"); }
inline int scan(int &pt) { return scanf("%d", &pt); }
inline int scan(char &pt) { return scanf("%c", &pt); }
inline int scan(long long &pt) { return scanf("%I64d", &pt); }
inline int scan(double &pt) { return scanf("%lf", &pt); }
inline int scan(char pt[]) { return scanf("%s", pt); }
struct pii {
  long long a;
  int i;
  friend int operator<(const pii &a, const pii &b) { return a.a > b.a; }
};
using namespace std;
int a[3000][3000];
long long b[3000][3000];
int n;
long long ka[6000];
long long kb[6000];
int main() {
  scan(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scan(a[i][j]);
      ka[i + j] += a[i][j];
      kb[3000 + i - j] += a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      b[i][j] = ka[i + j] + kb[3000 + i - j] - a[i][j];
    }
  }
  long long maxa = 0;
  int ia = 0;
  int ja = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i % 2; j < n; j += 2) {
      if (b[i][j] > maxa) {
        maxa = b[i][j];
        ia = i;
        ja = j;
      }
    }
  }
  long long maxb = 0;
  int ib = 0;
  int jb = 0;
  for (int i = 0; i < n; i++) {
    for (int j = !(i % 2); j < n; j += 2) {
      if (b[i][j] > maxb) {
        maxb = b[i][j];
        ib = i;
        jb = j;
      }
    }
  }
  print(maxa + maxb);
  print(ia + 1);
  print(ja + 1);
  print(ib + 1);
  print(jb + 1);
  return 0;
}
