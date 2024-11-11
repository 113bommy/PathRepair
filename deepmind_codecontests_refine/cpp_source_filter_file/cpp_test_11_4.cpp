#include <bits/stdc++.h>
template <class T>
void read(T &a) {
  a = 0;
  char x = getchar();
  bool f = 0;
  for (; x < '0' || x > '9'; x = getchar()) f |= x == '-';
  for (; x >= '0' && x <= '9'; x = getchar()) a = (a << 3) + (a << 1) + x - '0';
  if (f) a = -a;
}
template <class T, class... Args>
void read(T &a, Args &...args) {
  read(a);
  read(args...);
}
using namespace std;
const int N = 2e5 + 5;
int n;
int f[N], lim;
pair<int, int> d[N];
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first ^ b.first) {
    return a.first < b.first;
  }
  return a.second < b.second;
}
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) {
    read(d[i].first);
    d[i].second = i;
  }
  sort(d + 1, d + n + 1, cmp);
  int lim = 0;
  for (int i = 1; i <= n; ++i) {
    int c = d[i].second - d[i].first;
    if (c < 0) continue;
    if (lim == 0) {
      f[++lim] = c;
      continue;
    }
    if (c >= f[lim]) {
      f[++lim] = c;
      continue;
    }
    int l = 1, r = lim + 1;
    while (l < r - 1) {
      int mid = l + r >> 1;
      if (f[mid] <= c) {
        l = mid;
      } else {
        r = mid;
      }
    }
    if (f[l] > c) {
      f[l] = c;
    } else if (l != lim) {
      f[l + 1] = c;
    }
  }
  printf("%d\n", lim);
  return 0;
}
