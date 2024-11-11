#include <bits/stdc++.h>
using namespace std;
int main() {
  pair<int, int> a[3];
  for (int i = 0; i < 3; ++i) {
    scanf("%d %d", &a[i].first, &a[i].second);
  }
  sort(a, a + 3);
  if (a[0].second <= a[1].second && a[1].second <= a[2].second) {
    printf("%d\n", a[2].first - a[0].first + a[2].second - a[0].second + 1);
    for (int i = a[0].first; i <= a[1].first; ++i) {
      printf("%d %d\n", i, a[0].second);
    }
    for (int j = a[0].second + 1; j <= a[2].second; ++j) {
      printf("%d %d\n", a[1].first, j);
    }
    for (int i = a[1].first + 1; i <= a[2].first; ++i) {
      printf("%d %d\n", i, a[2].second);
    }
  } else if (a[0].second >= a[1].second && a[1].second >= a[2].second) {
    printf("%d\n", a[2].first - a[0].first + a[0].second - a[2].second + 1);
    for (int i = a[0].first; i <= a[1].first; ++i) {
      printf("%d %d\n", i, a[0].second);
    }
    for (int j = a[0].second + 1; j >= a[2].second; --j) {
      printf("%d %d\n", a[1].first, j);
    }
    for (int i = a[1].first + 1; i <= a[2].first; ++i) {
      printf("%d %d\n", i, a[2].second);
    }
  } else if ((a[0].second - a[1].second) * (a[0].second - a[2].second) <= 0) {
    printf("%d\n", a[2].first - a[0].first + 1 +
                       abs(a[1].second - a[0].second) +
                       abs(a[2].second - a[0].second));
    for (int i = a[0].first; i <= a[2].first; ++i) {
      printf("%d %d\n", i, a[0].second);
    }
    int d;
    if (a[1].second > a[0].second)
      d = 1;
    else
      d = -1;
    for (int j = a[0].second + d; j != a[1].second; j += d) {
      printf("%d %d\n", a[1].first, j);
    }
    printf("%d %d\n", a[1].first, a[1].second);
    if (a[2].second == a[0].second) return 0;
    if (a[2].second > a[0].second)
      d = 1;
    else
      d = -1;
    for (int j = a[0].second + d; j != a[2].second; j += d) {
      printf("%d %d\n", a[2].first, j);
    }
    printf("%d %d\n", a[2].first, a[2].second);
  } else {
    printf("%d\n", a[1].first - a[0].first + 1 +
                       abs(a[1].second - a[0].second) + a[2].first -
                       a[1].first);
    for (int i = a[0].first; i <= a[1].first; ++i) {
      printf("%d %d\n", i, a[0].second);
    }
    int d;
    if (a[1].second > a[0].second)
      d = 1;
    else
      d = -1;
    for (int j = a[0].second + d; j != a[1].second; j += d) {
      printf("%d %d\n", a[1].first, j);
    }
    printf("%d %d\n", a[1].first, a[1].second);
    for (int i = a[1].first + 1; i <= a[2].first; ++i) {
      printf("%d %d\n", i, a[2].second);
    }
  }
  return 0;
}
