#include <bits/stdc++.h>
using namespace std;
int n, d, a[500400], t[500400];
bool u[500400];
int q[500400], st = 0, fi = 0;
void add(int x) {
  for (int i = 500400 - 1; i >= x; --i) u[i] |= u[i - x];
}
void read(void) {
  cin >> n >> d;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
}
void kill(void) {
  u[0] = 1;
  int m = 0, s = 0;
  while (m < n && s + d >= a[m]) {
    s += a[m];
    add(a[m]);
    m++;
  }
  t[s] = 0;
  q[fi++] = s;
  for (int i = s - 1; i >= 0; --i)
    if (u[i]) {
      while (q[st] > i + d) st++;
      t[i] = t[q[st]] + 1;
      q[fi++] = i;
    }
  cout << s << " " << t[0] << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  read();
  kill();
  return 0;
}
