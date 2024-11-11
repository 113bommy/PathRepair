#include <bits/stdc++.h>
using namespace std;
const int MAXVAL = 200001;
long long n, k, a, b, q, bitA[MAXVAL], bitB[MAXVAL], t, x, y, dayTotal[MAXVAL];
int minimum(int x1, int x2) {
  if (x1 < x2) return x1;
  return x2;
}
void updateA(int pos, int val) {
  while (pos <= n) {
    bitA[pos] += val;
    pos += (pos & -pos);
  }
}
void updateB(int pos, int val) {
  while (pos <= n) {
    bitB[pos] += val;
    pos += (pos & -pos);
  }
}
int sumA(int pos) {
  int s = 0;
  while (pos > 0) {
    s += bitA[pos];
    pos -= (pos & -pos);
  }
  return s;
}
int sumB(int pos) {
  int s = 0;
  while (pos > 0) {
    s += bitB[pos];
    pos -= (pos & -pos);
  }
  return s;
}
int main() {
  cin >> n >> k >> a >> b >> q;
  for (int i = 0; i < q; i++) {
    cin >> t;
    if (t == 1) {
      cin >> x >> y;
      if (dayTotal[x] < a) updateA(x, minimum(y, a - dayTotal[x]));
      if (dayTotal[x] < b) updateB(x, minimum(y, b - dayTotal[x]));
      dayTotal[x] += y;
    } else {
      cin >> x;
      y = sumB(x - 1) + sumA(n) - sumA(x + k - 1);
      cout << y << "\n";
    }
  }
  return 0;
}
