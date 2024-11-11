#include <bits/stdc++.h>
using namespace std;
struct P {
  int x, y;
  bool operator<(const P &a) const { return y > a.y; };
};
int a, b, c, d, i, k, n, m, e, dx[10] = {1, 0, -1, 0, 1, 1, -1, -1},
                               dy[10] = {0, 1, 0, -1, 1, -1, 1, -1};
int o[2390101];
int l[1];
long long x, y, z, mod = 1000000007;
char r[1];
P u[1];
queue<int> q;
stack<int> s;
map<int, int> p[2];
vector<int> v[1];
bool as(P a, P b) { return a.y > b.y; }
void f(int n) {
  n += i - 1;
  for (; n; n /= 2) o[n]++;
}
void g(int n) {
  int p = 1;
  for (; p < i;) {
    o[p]--;
    if (o[p * 2] >= n)
      p *= 2;
    else
      n -= o[p * 2], p = p * 2 + 1;
  }
  o[p]--;
}
int main() {
  for (i = 1; i < 7; i *= 2)
    ;
  scanf("%d %d", &a, &b);
  for (int t = 1; t <= a; t++) {
    scanf("%d", &n);
    f(n);
  }
  for (int t = 1; t <= b; t++) {
    scanf("%d", &n);
    if (n < 0)
      g(-n);
    else
      f(n);
  }
  c = 1;
  for (; c < i;)
    if (o[c * 2])
      c *= 2;
    else
      c = c * 2 + 1;
  if (o[c])
    printf("%d", c - i + 1);
  else
    printf("0");
}
