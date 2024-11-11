#include <bits/stdc++.h>
using namespace std;
int MAX(int a, int b) { return (a > b) ? a : b; }
double FMAX(double a, double b) { return (a > b) ? a : b; }
int MIN(int a, int b) { return (a < b) ? a : b; }
double FMIN(double a, double b) { return (a < b) ? a : b; }
int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }
unsigned long long int UGCD(unsigned long long int a,
                            unsigned long long int b) {
  return b ? GCD(b, a % b) : a;
}
int LCM(int a, int b) { return a / GCD(a, b) * b; }
unsigned long long int LCM(unsigned long long int a, unsigned long long int b) {
  return a / GCD(a, b) * b;
}
void fswop(double &a, double &b) {
  double c = a;
  a = b;
  b = c;
}
void bez_swop(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}
void swop(int &a, int &b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}
long long int u(long long int a) {
  if (a >= 0) return a;
  return a * (-1);
}
int main() {
  vector<int> a;
  int i, j, n, r;
  char mas[10004];
  scanf("%d\n", &n);
  gets(mas);
  j = strlen(mas);
  i = 0;
  while (i < j) {
    r = 0;
    while (mas[i] != '.' && mas[i] != '!' && mas[i] != '?') {
      r++;
      i++;
    }
    a.push_back(r + 1);
    i += 2;
  }
  i = r = 0;
  while (i < a.size()) {
    j = a[i];
    if (j > n) {
      return !printf("Impossible");
    }
    i++;
    while (i < a.size() && (j + a[i] + 1) <= n) {
      j = j + a[i++] + 1;
    }
    r++;
  }
  printf("%d", r);
  return 0;
}
