#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
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
const double pi = 3.14159265358979323846264338327950288L;
const double eps = 1e-6;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int MAXN = 1005;
const int xi[] = {0, 0, 1, -1};
const int yi[] = {1, -1, 0, 0};
int N, T;
int main() {
  map<int, int> s;
  int n, x;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    s[x]++;
  }
  if (s.size() > 3)
    printf("NO\n");
  else if (s.size() <= 2)
    printf("YES\n");
  else {
    int i = 0, a[3];
    for (auto it = s.begin(); it != s.end(); it++) {
      a[i++] = it->second;
    }
    if (a[2] - a[1] != a[1] - a[0])
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
