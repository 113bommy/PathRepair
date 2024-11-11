#include <bits/stdc++.h>
using namespace std;
const int N = 3000030;
int n;
int p[N];
int t[N];
void update(int pos) {
  while (pos <= n) {
    t[pos]++;
    pos |= pos + 1;
  }
}
int get(int r) {
  int res = 0;
  while (r > 0) {
    res += t[r];
    r &= r + 1;
    r--;
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  int p1 = (3 * n) % 2, p2 = (7 * n + 1) % 2;
  long long s = 0;
  for (int i = n; i >= 1; i--) {
    s += get(p[i] - 1);
    update(p[i]);
  }
  s %= 2;
  if (s == p1)
    cout << "Petr";
  else
    cout << "Um_nik";
  return 0;
}
