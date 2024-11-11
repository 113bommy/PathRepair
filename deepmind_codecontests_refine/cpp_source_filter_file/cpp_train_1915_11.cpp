#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000000")
using namespace std;
const int size = 300010;
const long long alphabet = 130;
const long long INF = 1000000000;
const double pi = 4 * atan(1.0);
const long long MOD = 1000000007;
double a[30][30], Mi, M0, M, s[30];
int main() {
  int od = 0, minusod = 0;
  int n, m, x;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x == 1)
      ++od;
    else
      ++minusod;
  }
  int l, r;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &l, &r);
    int dov = r - l;
    if (!(dov & 1))
      printf("0\n");
    else {
      int lol = (r - l) / 2;
      if (lol <= od && lol <= minusod)
        printf("1\n");
      else
        printf("0\n");
    }
  }
  return 0;
}
