#include <bits/stdc++.h>
using namespace std;
pair<int, int> li[1050];
int n, m, ans, Ans[1050][2], t[1050];
inline int Read() {
  int x = 0;
  char y;
  do y = getchar();
  while (y < '0' || y > '9');
  do x = x * 10 + y - '0', y = getchar();
  while (y >= '0' && y <= '9');
  return x;
}
inline void Insert(int x, int y) {
  Ans[++ans][0] = x;
  Ans[ans][1] = y;
  t[y] -= t[x];
  t[x] <<= 1;
}
pair<int, int> Calc(int x, int y, int z) {
  if (t[y] < t[x]) swap(x, y);
  if (t[z] < t[x]) swap(x, z);
  if (t[z] < t[y]) swap(y, z);
  while (t[x]) {
    int q = 1, w = t[y] / t[x], e = t[z] / t[x];
    while (w)
      if (w & q)
        Insert(x, y), w -= q, q <<= 1;
      else
        Insert(x, z), e -= q, q <<= 1;
    swap(x, y);
    if (t[y] > t[z]) swap(y, z);
  }
  return make_pair(y, z);
}
void Solve(int x, int y) {
  pair<int, int> k = make_pair(li[x].second, li[x + 1].second);
  for (int i = x + 2; i <= y; i++) k = Calc(k.first, k.second, li[i].second);
}
int main() {
  n = Read();
  for (int i = 1; i <= n; i++) li[i].second = i, li[i].first = t[i] = Read();
  sort(li + 1, li + n + 1);
  int le = 1;
  while (li[le].first == 0 && le <= n) le++;
  if (le > n - 1) {
    puts("-1");
    return 0;
  }
  Solve(le, n);
  cout << ans << endl;
  for (int i = 1; i <= ans; i++) printf("%d %d\n", Ans[i][0], Ans[i][1]);
  return 0;
}
