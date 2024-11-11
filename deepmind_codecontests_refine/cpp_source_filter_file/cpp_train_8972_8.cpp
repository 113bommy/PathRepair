#include <bits/stdc++.h>
using namespace std;
template <class t>
inline t read(t &x) {
  bool f = 0;
  char c = getchar();
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
int n;
deque<int> ans;
vector<pair<long long, int>> s;
long long que1(int x, int y, int z) {
  cout << "1 " << x << " " << y << " " << z << endl;
  long long res;
  return read(res);
}
int que2(int x, int y, int z) {
  cout << "2 " << x << " " << y << " " << z << endl;
  int res;
  return read(res);
}
signed main() {
  read(n);
  int fi = 1, se = 2;
  for (int i = 3; i <= n; i++)
    if (que2(fi, se, i) == -1) se = i;
  for (int i = 2; i <= n; i++)
    if (i ^ se) s.emplace_back(que1(fi, se, i), i);
  sort(s.begin(), s.end());
  int top = s.back().second;
  ans.push_back(top);
  s.pop_back();
  reverse(s.begin(), s.end());
  for (auto [x, i] : s) {
    if (que2(fi, top, i) == -1)
      ans.push_front(i);
    else
      ans.push_back(i);
  }
  ans.push_back(fi);
  ans.push_front(se);
  printf("0 ");
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
}
