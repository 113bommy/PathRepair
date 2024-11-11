#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool scan_d(T &ret) {
  char c;
  int sgn;
  if (c = getchar(), c == EOF) return 0;
  while (c != '-' && (c < '0' || c > '9')) {
    if ((c = getchar()) == EOF) return 0;
  }
  sgn = (c == '-') ? -1 : 1;
  ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  ret *= sgn;
  return 1;
}
template <typename T>
void print(T x) {
  static char s[33], *s1;
  s1 = s;
  if (!x) *s1++ = '0';
  if (x < 0) putchar('-'), x = -x;
  while (x) *s1++ = (x % 10 + '0'), x /= 10;
  while (s1-- != s) putchar(*s1);
}
template <typename T>
void println(T x) {
  print(x);
  putchar('\n');
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  while (cin >> n >> m >> k) {
    int sum = 0;
    int arr1[111], arr2[111];
    int Marr[111] = {};
    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int i = 0; i < n; i++) {
      cin >> arr2[i];
      Marr[arr2[i]] = max(Marr[arr2[i]], arr1[i]);
    }
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      if (Marr[arr2[x]] != arr1[x]) sum++;
    }
    printf("%d\n", sum);
  }
  return 0;
}
