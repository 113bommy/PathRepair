#include <bits/stdc++.h>
using namespace std;
struct p {
  int a, b;
};
bool compare(p p1, p p2) {
  if (p1.a < p2.a)
    return true;
  else
    return false;
}
int main() {
  int n, m;
  cin >> n >> m;
  p P[m];
  int a, b;
  bool ans = true;
  int ma = -1;
  int mi = 1000000;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    if (a > b) {
      int t = a;
      a = b;
      b = t;
    }
    if (a > ma) ma = a;
    if (b < mi) mi = b;
    P[i].a = a;
    P[i].b = b;
  }
  sort(P, P + m, compare);
  int a1 = P[0].a;
  int b1 = P[0].b;
  for (int i = 1; i < m; i++) {
    if (P[i].a >= b1) {
      ans = false;
      break;
    }
  }
  if (m == 0)
    cout << n - 1;
  else {
    if (ans) {
      cout << mi - ma;
    } else {
      cout << 0;
    }
  }
  return 0;
}
