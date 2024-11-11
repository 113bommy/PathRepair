#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T& n) {
  char ch;
  int sign = 1;
  while (!isdigit(ch = getchar()))
    if (ch == '-') sign = -1;
  n = ch - '0';
  while (isdigit(ch = getchar())) n = n * 10 + ch - '0';
  n *= sign;
}
const int INF = 1e9 + 7;
const int N = 222222;
int n;
int a[N], vis[N];
int main() {
  read(n);
  for (int i = (1); i <= (n); ++i) read(a[i]);
  int ans = 1;
  for (int i = (1); i <= (n); ++i) {
    if (!vis[a[i]])
      vis[a[i]] = 1;
    else
      ans++;
  }
  printf("%d\n", ans);
  return 0;
}
