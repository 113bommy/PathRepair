#include <bits/stdc++.h>
using namespace std;
inline void print(char pt) { printf("%c\n", pt); }
inline void print(int pt) { printf("%d\n", pt); }
inline void print(long long pt) { printf("%I64d\n", pt); }
inline void print(double pt) { printf("%f\n", pt); }
inline void print(char pt[]) { printf("%s\n", pt); }
inline void scan(int &pt) { scanf("%d", &pt); }
inline void scan(long long &pt) { scanf("%I64d", &pt); }
inline void scan(double &pt) { scanf("%lf", &pt); }
inline void scan(char pt[]) { scanf("%s", pt); }
struct pii {
  int a;
  int b;
  friend int operator<(pii a, pii b) {
    if (a.a != b.a) return a.a < b.a;
    return a.b < b.b;
  }
};
struct str {
  char val[30];
  friend int operator<(str a, str b) { return strcmp(a.val, b.val) < 0; }
};
int T;
int n, m;
char a[1000];
int main() {
  scan(n);
  scan(a);
  sort(a, a + n);
  sort(a + n, a + 2 * n);
  for (int i = 0; i < n; i++) {
    if (a[i] < a[i + n]) break;
    if (i == n - 1) {
      print("YES");
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] > a[i + n]) break;
    if (i == n - 1) {
      print("YES");
      return 0;
    }
  }
  print("NO");
  return 0;
}
