#include <bits/stdc++.h>
using namespace std;
int xxx, k, a[1000011], n;
int nxt() {
  int r = 0;
  while (1) {
    char c = getchar();
    if (c == EOF || c == 10) xxx = 1;
    if (c == ' ' || c == '-' || c == EOF || c == 10) break;
    ++r;
  }
  return r;
}
bool check(int l) {
  int r = 1, L = 0;
  for (int i = 0; i < n; ++i) {
    if (L + a[i] > l) {
      ++r;
      L = 0;
    }
    if (L + a[i] > l) return 0;
    L += a[i];
  }
  return r <= k;
}
int main() {
  cin >> k;
  getchar();
  while (!xxx) a[n++] = nxt() + 1;
  a[n - 1]--;
  int d = 1, c = 1000001, r;
  while (d <= c) {
    int g = (d + c) / 2;
    if (check(g)) {
      r = g;
      c = g - 1;
    } else
      d = g + 1;
  }
  cout << r;
}
