#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = 0x7fffffff;
const int dir4[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const double eps = 1e-8;
const double PI = acos(-1.0);
inline int sign(double x) { return (x > eps) - (x < -eps); }
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <class T>
inline T Min(T a, T b) {
  return a < b ? a : b;
}
template <class T>
inline T Max(T a, T b) {
  return a > b ? a : b;
}
int n;
int in[101];
int ans = 2147483647;
void dfs(char c, int now, int temp) {
  if (now >= n) {
    ans = Min(ans, temp);
    return;
  }
  if (in[now] == 0) {
    c = '0';
    temp++;
  } else if (in[now] == 1) {
    if (c == 'c') {
      c = '0';
      temp++;
    } else {
      c = 'c';
    }
  } else if (in[now] == 2) {
    if (c == 's') {
      c = '0';
      temp++;
    } else {
      c = 's';
    }
  } else if (in[now] == 3) {
    if (c == 's') {
      c = 'c';
    } else if (c == 'c') {
      c = 's';
    }
  }
  now++;
  dfs(c, now, temp);
}
int main() {
  while (~scanf("%d", &(n))) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &(in[i]));
    }
    if (in[0] == 0)
      dfs('0', 1, 0);
    else if (in[0] == 1)
      dfs('c', 1, 0);
    else if (in[0] == 2) {
      dfs('s', 1, 0);
    } else if (in[0] == 3) {
      dfs('c', 1, 0);
      dfs('s', 1, 0);
    }
    printf("%d\n", (ans));
  }
  return 0;
}
