#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &first) {
  char c;
  bool nega = 0;
  while ((!isdigit(c = getchar())) && (c != '-'))
    ;
  if (c == '-') {
    nega = 1;
    c = getchar();
  }
  first = c - 48;
  while (isdigit(c = getchar())) first = first * 10 + c - 48;
  if (nega) first = -first;
}
template <typename T>
inline void writep(T first) {
  if (first > 9) writep(first / 10);
  putchar(first % 10 + 48);
}
template <typename T>
inline void write(T first) {
  if (first < 0) {
    putchar('-');
    first = -first;
  }
  writep(first);
}
template <typename T>
inline void writeln(T first) {
  write(first);
  putchar('\n');
}
const int N = 2e5 + 5;
int d, n, m;
pair<int, int> a[N];
set<pair<int, int> > S;
int main() {
  read(d);
  read(n);
  read(m);
  for (int i = 1; i <= m; i++) {
    read(a[i].first);
    read(a[i].second);
  }
  sort(a + 1, a + m + 1);
  a[0] = {0, 0};
  a[m++] = {d, 0};
  int j = 0;
  long long res = 0;
  for (int i = 0; i < m - 1; i++) {
    int cur = a[i].first;
    S.insert({a[i].second, a[i].first});
    while (cur < a[i + 1].first) {
      while (j <= i && a[j].first + n <= cur) {
        S.erase({a[j].second, a[j].first});
        j++;
      }
      if (S.empty()) {
        puts("-1");
        return 0;
      }
      int use = min(a[i + 1].first - cur, n - (cur - S.begin()->second));
      res += 1LL * use * S.begin()->first;
      cur += use;
    }
  }
  write(res);
  return 0;
}
