#include <bits/stdc++.h>
using namespace std;
bool boy[111], girl[111];
int lcm(int a, int b) {
  int r, ta = a, tb = b;
  do {
    r = tb % ta;
    ta = tb;
    tb = r;
  } while (r != 0);
  return (a / ta) * b;
}
int main() {
  int n, m, i, u, g;
  scanf("%d%d", &n, &m);
  scanf("%d", &u);
  for (i = 0; i < u; i++) {
    int t;
    scanf("%d", &t);
    boy[t] = true;
  }
  scanf("%d", &u);
  for (i = 0; i < u; i++) {
    int t;
    scanf("%d", &t);
    girl[t] = true;
  }
  g = lcm(n, m);
  for (i = 0; i <= g; i++) {
    boy[i % n] = boy[i % n] || girl[i % m];
    girl[i % m] = boy[i % n] || girl[i % m];
  }
  bool ans = true;
  for (i = 0; i < n; i++) ans = ans && boy[i];
  for (i = 0; i < m; i++) ans = ans && girl[i];
  cout << (ans ? "Yes" : "No");
  return 0;
}
