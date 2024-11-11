#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 3e3 + 10;
int flag[N];
int a[] = {
    0, 1, 2, 3, 4, 8, 12, 5, 10, 15, 6, 11, 13, 7, 9, 14,
};
int offset[][3] = {
    16, 32, 48, 17, 34, 51, 18, 35, 49, 19, 33, 50, 20, 40, 60, 21,
    42, 63, 22, 43, 61, 23, 41, 62, 24, 44, 52, 25, 46, 55, 26, 47,
    53, 27, 45, 54, 28, 36, 56, 29, 38, 59, 30, 39, 57, 31, 37, 58,
};
void output(int b) {
  string s;
  while (b) {
    s.push_back(b % 2 + '0');
    b /= 2;
  }
  reverse(s.begin(), s.end());
  printf(s.c_str());
  putchar(' ');
}
long long check(int cnt) {
  int d[4] = {0, 3, 1, 2};
  long long res = 0;
  long long o = 1;
  while (cnt) {
    res += d[cnt % 4] * o;
    o *= 4;
    cnt /= 4;
  }
  return res;
}
int main() {
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 3; j++) {
      offset[i][j] -= 16 * (j + 1);
    }
  }
  int ncase;
  scanf("%d", &ncase);
  while (ncase--) {
    long long n;
    scanf("%lld", &n);
    if (n <= 15)
      printf("%d\n", a[n]);
    else {
      n -= 16;
      long long cur = 16;
      int cnt = 2;
      while (n >= cur * 3) {
        cnt++;
        n -= cur * 3;
        cur *= 4;
      }
      long long key = cur;
      int oo = n % 48;
      long long ans1 = cur + n / 3;
      long long ans3 = check(n / 3) + cur * 3;
      long long ans2 = ans1 ^ ans3;
      long long ans[] = {ans1, ans2, ans3};
      printf("%lld\n", ans[n % 3]);
    }
  }
  return 0;
}
