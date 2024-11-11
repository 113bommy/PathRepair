#include <bits/stdc++.h>
using namespace std;
int Num;
const long long inf = 999999999;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
pair<int, pair<int, int> > p[1000500];
int main() {
  int n = read();
  for (int i = 0; i < n; i++) {
    p[i].first = read();
    p[i].first %= 1050;
    p[i].second.first = read();
    p[i].second.second = i;
  }
  sort(p, p + n);
  for (int i = 0; i < n; i++) printf("%d ", p[i].second.second + 1);
}
