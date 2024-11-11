#include <bits/stdc++.h>
using namespace std;
int m, n, j, k, l, i, o, p, __t, A[10], cnt;
char ch;
void read(int &a) {
  for (ch = getchar(); (ch < '0' || ch > '9') && (ch != '-'); ch = getchar())
    ;
  if (ch == '-')
    a = 0, __t = -1;
  else
    a = ch - '0', __t = 1;
  for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
    a = a * 10 + ch - '0';
  a *= __t;
}
int ans0, ans1, ans2, ans(100000000);
inline void check(int i, int j, int k) {
  if (j < i || k < i || k < j) return;
  if (abs(A[3] * i - A[4] * j) + abs(A[4] * j - A[5] * k) < ans)
    ans = abs(A[3] * i - A[4] * j) + abs(A[4] * j - A[5] * k), ans0 = i,
    ans1 = j, ans2 = k;
}
int gcd(int a, int b) { return (a % b == 0) ? (b) : (gcd(b, a % b)); }
int main() {
  read(m), read(n);
  for (int i = 1; i <= m; i++) {
    read(k);
    A[k]++;
  }
  for (int i = n / (A[3] + A[4] + A[5]); i >= 0; i--) {
    int surplus = (n - A[3] * i);
    if (surplus % (gcd(A[4], A[5])) != 0) continue;
    for (int j = min(surplus / (A[4] + A[5]), (A[3] * i + ans) / A[4]);
         j >= (max((A[3] * i - ans) / A[4], i)); j--) {
      cnt++;
      int k = (surplus - j * A[4]) / A[5];
      if (A[5] * k - A[4] * j > ans || A[3] * i - A[4] * j > ans ||
          A[3] * i - A[4] * j + A[5] * k - A[4] * j > ans)
        break;
      if (A[3] * i + A[4] * j + A[5] * k != n) continue;
      check(i, j, k);
    }
  }
  if (ans == 100000000)
    printf("-1\n");
  else
    printf("%d %d %d\n", ans0, ans1, ans2);
}
