#include <bits/stdc++.h>
using namespace std;
inline long long max(long long a, long long b) { return a > b ? a : b; }
inline void read(int *a) {
  register char c = 0;
  while (c < 33) c = getchar();
  *a = 0;
  while (c > 33) *a = *a * 10 + c - '0', c = getchar();
}
int main() {
  int n, m, w, h;
  int a[100005];
  long long p = 1;
  cin >> n;
  for (int i = 0; i < n; i++) read(&a[i]);
  cin >> m;
  for (int i = 0; i < m; i++)
    read(&w), read(&h), p = max(p, (long long)a[w - 1]) + h,
                        printf("%I64d ", p - h);
}
