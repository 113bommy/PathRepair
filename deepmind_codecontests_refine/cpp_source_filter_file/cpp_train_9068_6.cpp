#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  int fh = 1;
  while (!isdigit(c)) {
    if (c == '-') fh = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  x *= fh;
}
struct Info {
  long long x, y, z;
} a[1000010];
int n, li[1000010];
long long dp[1000010], ansn;
bool comp(const Info &a, const Info &b) { return a.x < b.x; }
long long ny(int x) { return dp[x]; }
long long nx(int x) { return a[x].x; }
long double xie(int x, int y) {
  return ((long double)(ny(y) - ny(x))) / (nx(y) - nx(x));
}
int main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    read(a[i].x);
    read(a[i].y);
    read(a[i].z);
  }
  sort(a + 1, a + n + 1, comp);
  int l = 1, r = 1;
  li[l] = 0;
  for (int i = 1; i <= n; i++) {
    while (l < r &&
           (ny(li[l + 1]) - ny(li[l])) >= (nx(li[l + 1]) - nx(li[l])) * a[i].y)
      l++;
    dp[i] = ny(li[l]) - nx(li[l]) * a[i].y + a[i].x * a[i].y - a[i].z;
    while (l < r && xie(li[r], i) <= xie(li[r - 1], li[r])) r--;
    li[++r] = i;
  }
  for (int i = 1; i <= n; i++) ansn = max(ansn, dp[i]);
  cout << ansn << endl;
  return 0;
}
