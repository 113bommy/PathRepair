#include <bits/stdc++.h>
using namespace std;
int IN() {
  int c, f, x;
  while (!isdigit(c = getchar()) && c != '-')
    ;
  c == '-' ? (f = 1, x = 0) : (f = 0, x = c - '0');
  while (isdigit(c = getchar())) x = (x << 1) + (x << 3) + c - '0';
  return !f ? x : -x;
}
const int N = 100000 + 19;
const int p = 1e9 + 7;
char s[N];
int A[128];
int n, mx, cnt;
int Pow(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = 1ll * a * a % p)
    if (b & 1) res = 1ll * res * a % p;
  return res;
}
int main() {
  n = IN();
  scanf("%s", s + 1);
  for (int i = 1; i < n + 1; i++) {
    A[s[i] - 'A']++;
  }
  for (int i = 1; i < 128; i++) {
    if (A[i] > mx) mx = A[i], cnt = 0;
    if (A[i] == mx) cnt++;
  }
  printf("%d\n", Pow(cnt, n));
}
