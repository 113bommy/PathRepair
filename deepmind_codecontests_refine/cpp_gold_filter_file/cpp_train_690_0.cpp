#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return f * x;
}
inline void write(long long a) {
  if (a < 0) putchar('-'), a = -a;
  if (a >= 10) write(a / 10);
  putchar(a % 10 + '0');
}
const int MAX_N = 3e5 + 10;
int c[MAX_N], n, x1, x2;
pair<int, int> p[MAX_N];
int main() {
  scanf("%d%d%d", &n, &x1, &x2);
  for (int i = 0; i < n; i++) {
    int temp;
    scanf("%d", &temp);
    p[i] = make_pair(temp, i + 1);
  }
  sort(p, p + n);
  for (int i = 0; i < n; i++) {
    int t = (x1 + p[i].first - 1) / p[i].first + i;
    if (t >= n) {
      continue;
    }
    int f = (x2 + p[t].first - 1) / p[t].first + t;
    if (f > n) {
      continue;
    }
    puts("Yes");
    printf("%d %d\n", t - i, f - t);
    for (int j = i; j < t; j++) {
      printf("%d ", p[j].second);
    }
    puts("");
    for (int j = t; j < f; j++) {
      printf("%d ", p[j].second);
    }
    return 0;
  }
  for (int i = 0; i < n; i++) {
    int t = (x2 + p[i].first - 1) / p[i].first + i;
    if (t >= n) {
      continue;
    }
    int f = (x1 + p[t].first - 1) / p[t].first + t;
    if (f > n) {
      continue;
    }
    puts("Yes");
    printf("%d %d\n", f - t, t - i);
    for (int j = t; j < f; j++) {
      printf("%d ", p[j].second);
    }
    puts("");
    for (int j = i; j < t; j++) {
      printf("%d ", p[j].second);
    }
    return 0;
  }
  puts("No");
  return 0;
}
