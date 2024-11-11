#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
int tmp[1005];
int nextInt() {
  int n;
  scanf("%d", &n);
  return n;
}
long long int nextLong() {
  long long int n;
  cin >> n;
  return n;
}
double nextDouble() {
  double n;
  scanf("%lf", &n);
  return n;
}
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
bool MyCompare(int a, int b) { return a < b; }
int main() {
  int n = nextInt(), m = nextInt();
  for (int i = 0; i < n; i++) scanf("%s", a[i]);
  memset(tmp, 0, sizeof(tmp));
  int ff = 0;
  for (int i = 0; i < n; i++) {
    int f = 0;
    int steps = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'G') f = 1;
      if (a[i][j] == 'S')
        if (f == 0)
          ff = 1;
        else {
          f = 0;
          steps++;
        }
      if (f) steps++;
    }
    tmp[steps]++;
  }
  if (ff)
    printf("-1");
  else {
    int kol = 0;
    for (int i = 0; i < 1005; i++)
      if (tmp[i]) kol++;
    printf("%d", kol);
  }
  return 0;
}
