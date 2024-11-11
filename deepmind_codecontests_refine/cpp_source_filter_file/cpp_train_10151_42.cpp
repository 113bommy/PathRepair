#include <bits/stdc++.h>
using namespace std;
long long w, a, b;
long long nod(long long a, long long b) {
  while (a > 0 && b > 0) {
    if (a > b)
      a %= b;
    else
      b %= a;
  }
  return a + b;
}
long long nok(long long a, long long b) {
  long long del = nod(a, b);
  return (a / del) * b;
}
long double c, d;
void sokr(long long ch, long long zn) {
  long long r = nod(ch, zn);
  cout << ch / r << "/" << zn / r;
  exit(0);
}
int main() {
  cin >> w >> a >> b;
  if (a == b) {
    cout << "1/1";
    return 0;
  }
  if (w < min(a, b)) {
    cout << "1/1";
    return 0;
  }
  c = a;
  d = b;
  long long rrr = nod(a, b);
  long double rrrr = rrr * 1.0;
  long double q = (c * d) / rrrr;
  if (q - 0.00001 > w) {
    sokr(min(a, b) - 1, w);
    return 0;
  }
  long long cycle = nok(a, b);
  long long full = ((w - 1) / cycle);
  long long total = full * min(a, b);
  long long lest = w - full * cycle + 1;
  total += min(min(a, b), lest);
  total--;
  sokr(total, w);
  return 0;
}
