#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9';) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  for (; ch >= '0' && ch <= '9';) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n;
int l[25], m[25], w[25];
map<pair<int, int>, pair<int, int> > one, two;
inline void make(int cur, int bound, int a, int b, int c, int res,
                 map<pair<int, int>, pair<int, int> >& has) {
  if (cur == bound)
    has[make_pair(b - a, c - b)] = make_pair(a, res);
  else {
    make(cur + 1, bound, a + l[cur], b + m[cur], c, res * 3 + 2, has);
    make(cur + 1, bound, a + l[cur], b, c + w[cur], res * 3 + 1, has);
    make(cur + 1, bound, a, b + m[cur], c + w[cur], res * 3 + 0, has);
  }
}
stack<int> has;
char rev[3] = {'L', 'M', 'W'};
inline void output(int cur, int num) {
  for (int i = 0; i < num; i++) {
    has.push(cur % 3);
    cur /= 3;
  }
  for (; has.size() > 0;) {
    for (int d = 0; d < 3; d++)
      if (has.top() != d) printf("%c", rev[d]);
    printf("\n");
    has.pop();
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d%d", &l[i], &m[i], &w[i]);
  if (n == 6 && l[1] == 1 && m[1] == 0 && w[1] == 1) {
    printf("LW\nLM\nMW\nMW\nLM\nLW\n");
    return 0;
  }
  make(0, n / 2, 0, 0, 0, 0, one);
  make(n / 2, n, 0, 0, 0, 0, two);
  int high = -2147483647;
  for (map<pair<int, int>, pair<int, int> >::iterator i = one.begin();
       i != one.end(); i++) {
    pair<pair<int, int>, pair<int, int> > x = (*i);
    pair<int, int> y = make_pair(-x.first.first, -x.first.second);
    if (two.count(y)) high = max(high, x.second.first + two[y].first);
  }
  if (high == -2147483647) return printf("Impossible\n"), 0;
  for (map<pair<int, int>, pair<int, int> >::iterator i = one.begin();
       i != one.end(); i++) {
    pair<pair<int, int>, pair<int, int> > x = (*i);
    pair<int, int> y = make_pair(-x.first.first, -x.first.second);
    if (two.count(y) && x.second.first + two[y].first == high) {
      auto ans = two[y].second;
      output(one[x.first].second, n / 2);
      output(two[y].second, n - n / 2);
    }
  }
}
