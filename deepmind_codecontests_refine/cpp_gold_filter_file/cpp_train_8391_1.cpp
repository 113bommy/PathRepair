#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = 1e-6;
inline int readint() {
  int sum = 0;
  char c = getchar();
  bool f = 0;
  while (c < '0' || c > '9') {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return f ? -sum : sum;
}
inline long long readLL() {
  long long sum = 0;
  char c = getchar();
  bool f = 0;
  while (c < '0' || c > '9') {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return f ? -sum : sum;
}
int k[105], f[105];
inline bool check(int i, int j) {
  if ((k[j] - 1) / i + 1 != f[j]) return false;
  return true;
}
vector<int> ans;
set<int> s;
int main() {
  int n = readint(), m = readint();
  for (int i = 1; i <= m; i++) k[i] = readint(), f[i] = readint();
  int pos = 0;
  for (int i = 1; i <= 100; i++) {
    bool fg = true;
    for (int j = 1; j <= m; j++) {
      if (!check(i, j)) {
        fg = false;
        break;
      }
    }
    if (fg) {
      pos = i;
      ans.push_back(i);
    }
  }
  if (!int((ans).size())) {
    printf("-1\n");
  } else {
    for (int i = 0; i < int((ans).size()); i++) s.insert((n - 1) / ans[i] + 1);
    if (s.size() > 1)
      printf("-1\n");
    else
      printf("%d\n", *s.begin());
  }
  return 0;
}
