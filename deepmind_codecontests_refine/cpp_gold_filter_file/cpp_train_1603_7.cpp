#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') positive = 0;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
int N, M;
pair<pair<int, int>, int> a[1000006];
priority_queue<pair<int, int> > Q;
bool ans[1000006];
vector<int> v;
int main() {
  N = read(), M = read();
  for (int i = 1; i <= M; ++i) {
    int l = read(), r = read() + l;
    a[i] = make_pair(make_pair(l, -r), i);
  }
  sort(a + 1, a + M + 1);
  int now = 0;
  for (int i = 1; i <= M; ++i) {
    if (a[i].first.first > now) {
      if (!Q.empty() && Q.top().first > now) {
        now = Q.top().first;
        ans[Q.top().second] = 1;
        Q.pop();
      }
    }
    Q.push(make_pair(-a[i].first.second, a[i].second));
  }
  if (!Q.empty() && Q.top().first > now) ans[Q.top().second] = 1;
  for (int i = 1; i <= M; ++i)
    if (!ans[i]) v.push_back(i);
  printf("%d\n", v.size());
  for (int i = 0; i < v.size(); ++i)
    printf("%d%c", v[i], i < v.size() - 1 ? ' ' : '\n');
  return 0;
}
