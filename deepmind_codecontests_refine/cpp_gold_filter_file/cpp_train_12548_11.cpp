#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
struct Long {
  int n, a[500];
  void cl() {
    while (n > 0 && !a[n - 1]) n--;
  }
  void out() {
    for (int i = n - 1; i >= 0; i--) cout << a[i];
  }
};
Long Mult(Long a, Long b) {
  Long c;
  c.n = a.n + b.n;
  for (int i = 0; i < c.n; i++) c.a[i] = 0;
  for (int i = a.n; i < c.n; i++) a.a[a.n++] = 0;
  for (int i = a.n; i < c.n; i++) a.a[a.n++] = 0;
  for (int i = 0; i < a.n; i++)
    for (int j = 0; j < b.n; j++) c.a[i + j] += a.a[i] * b.a[j];
  for (int i = 0; i < c.n; i++) {
    if (c.a[i] > 10 && i == c.n - 1) c.a[c.n++] = 0;
    if (c.a[i] > 10) c.a[i + 1] += c.a[i] / 10, c.a[i] %= 10;
  }
  c.cl();
  return c;
}
int pr[] = {2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,
            43,  47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101,
            103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
            173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229};
Long tolong(int x) {
  Long q;
  q.n = 0;
  while (x > 0) q.a[q.n++] = x % 10, x /= 10;
  q.cl();
  return q;
}
int main() {
  int n;
  cin >> n;
  if (n == 2) {
    cout << "-1";
    return 0;
  }
  Long a[60];
  for (int i = 0; i < n; i++) a[i] = tolong(1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        Long w = tolong(pr[i]);
        a[j] = Mult(a[j], tolong(pr[i]));
      }
    }
  }
  for (int i = 0; i < n; i++) {
    a[i].out();
    cout << endl;
  }
  return 0;
}
