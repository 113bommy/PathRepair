#include <bits/stdc++.h>
using namespace std;
const int maxn = 5;
inline long long rd() {
  long long x = 0;
  char c = getchar();
  int neg = 1;
  while (c < '0' || c > '9') {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * neg;
}
pair<int, int> p[maxn];
int main() {
  int i, j, k;
  for (i = 1; i <= 3; i++) p[i].first = rd(), p[i].second = rd();
  sort(p + 1, p + 4);
  if (p[1].second <= p[2].second && p[1].second <= p[3].second) {
    if (p[2].second <= p[3].second) {
      int ans = p[2].second - p[1].second + p[3].first - p[1].first +
                p[3].second - p[2].second + 1;
      printf("%d\n", ans);
      for (i = p[1].second; i <= p[2].second; i++)
        printf("%d %d\n", p[1].first, i);
      for (i = p[1].first + 1; i <= p[3].first; i++)
        printf("%d %d\n", i, p[2].second);
      for (i = p[2].second + 1; i <= p[3].second; i++)
        printf("%d %d\n", p[3].first, i);
    } else {
      int ans = p[3].second - p[1].second + p[3].first - p[1].first +
                p[2].second - p[3].second + 1;
      printf("%d\n", ans);
      for (i = p[1].second; i <= p[3].second; i++)
        printf("%d %d\n", p[1].first, i);
      for (i = p[1].first + 1; i <= p[3].first; i++)
        printf("%d %d\n", i, p[3].second);
      for (i = p[3].second + 1; i <= p[2].second; i++)
        printf("%d %d\n", p[2].first, i);
    }
  } else if (p[1].second <= p[2].second && p[1].second > p[3].second) {
    int ans = p[1].second - p[3].second + p[3].first - p[1].first +
              p[2].second - p[1].second + 1;
    printf("%d\n", ans);
    for (i = p[3].second; i <= p[1].second; i++)
      printf("%d %d\n", p[3].first, i);
    for (i = p[1].first; i <= p[3].first - 1; i++)
      printf("%d %d\n", i, p[1].second);
    for (i = p[1].second + 1; i <= p[2].second; i++)
      printf("%d %d\n", p[2].first, i);
  } else if (p[1].second > p[2].second && p[1].second <= p[3].second) {
    int ans = p[3].second - p[1].second + p[3].first - p[1].first +
              p[1].second - p[2].second + 1;
    printf("%d\n", ans);
    for (i = p[1].second; i <= p[3].second; i++)
      printf("%d %d\n", p[3].first, i);
    for (i = p[1].first; i <= p[3].first - 1; i++)
      printf("%d %d\n", i, p[1].second);
    for (i = p[2].second; i <= p[1].second - 1; i++)
      printf("%d %d\n", p[2].first, i);
  } else if (p[1].second > p[2].second && p[1].second > p[3].second) {
    if (p[2].second <= p[3].second) {
      int ans = p[1].second - p[2].second + p[2].first - p[1].first +
                p[3].first - p[2].first + 1;
      printf("%d\n", ans);
      for (i = p[1].first; i <= p[3].first; i++)
        printf("%d %d\n", i, p[3].second);
      for (i = p[2].second; i <= p[3].second - 1; i++)
        printf("%d %d\n", p[2].first, i);
      for (i = p[3].second + 1; i <= p[1].second; i++)
        printf("%d %d\n", p[1].first, i);
    } else {
      int ans = p[3].first - p[1].first + p[1].second - p[3].second + 1;
      printf("%d\n", ans);
      for (i = p[2].second; i <= p[1].second; i++)
        printf("%d %d\n", p[1].first, i);
      for (i = p[1].first + 1; i <= p[3].first; i++)
        printf("%d %d\n", i, p[2].second);
      for (i = p[3].second; i <= p[2].second - 1; i++)
        printf("%d %d\n", p[3].first, i);
    }
  }
  return 0;
}
