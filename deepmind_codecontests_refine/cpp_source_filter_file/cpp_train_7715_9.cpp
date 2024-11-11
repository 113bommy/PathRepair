#include <bits/stdc++.h>
int n;
char s[200001];
int x, y;
void Select(char c) {
  if (c == 'U') --y;
  if (c == 'D') ++y;
  if (c == 'L') ++x;
  if (c == 'R') --x;
}
void UnSelect(char c) {
  if (c == 'U') ++y;
  if (c == 'D') --y;
  if (c == 'L') --x;
  if (c == 'R') ++x;
}
bool Possible(int len) {
  bool result = false;
  for (int i = -len, j = 0; i < n; ++i, ++j) {
    if (i >= 0 && j <= n && abs(x) + abs(y) <= len) {
      result = true;
    }
    if (i >= 0) {
      Select(s[i]);
    }
    if (j < n) {
      UnSelect(s[j]);
    }
  }
  return result;
}
int main() {
  scanf("%d", &n);
  scanf("%s", s);
  scanf("%d%d", &x, &y);
  for (int i = 0; i < n; ++i) {
    Select(s[i]);
  }
  if (abs(x) + abs(y) % 2 == 1) {
    printf("-1\n");
    return 0;
  }
  int lo = 0;
  int hi = n + 1;
  while (lo < hi) {
    const int mid = (lo + hi) / 2;
    if (Possible(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  if (lo == n + 1) {
    printf("-1\n");
  } else {
    printf("%d\n", lo);
  }
  return 0;
}
