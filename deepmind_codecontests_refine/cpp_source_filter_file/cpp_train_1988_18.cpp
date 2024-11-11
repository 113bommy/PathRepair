#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
const long double PI = acos(0.0) * 2.0;
mt19937_64 rng((unsigned long long)new char);
const int mod = 1e9 + 7;
const long long INF = 9e18;
const int maxn = 1e6 + 100;
int ask(int i) {
  cout << "? " << i << endl;
  fflush(stdout);
  int x;
  cin >> x;
  return x;
}
int n;
int d(int i) {
  int c = i, s = i;
  if (s > (n >> 1))
    s -= (n >> 1);
  else
    s += (n >> 1);
  return ask(c) - ask(s);
}
void answ(int i) {
  cout << "! " << i << endl;
  fflush(stdout);
}
int main() {
  cin >> n;
  assert(!(n & 1));
  if (ask(1) & 1) {
    answ(-1);
    return 0;
  }
  int l = 1, r = 1 + (n >> 1);
  int a = d(l), b = d(r);
  if (a == 0) {
    return answ(l), 0;
  }
  if (b == 0) return answ(r), 0;
  bool fl = a < 0;
  while (r - l > 1) {
    if (fl) {
      if (d(((l + r) >> 1)) <= 0)
        l = ((l + r) >> 1);
      else
        r = ((l + r) >> 1);
    } else {
      if (d(((l + r) >> 1)) <= 0)
        r = ((l + r) >> 1);
      else
        l = ((l + r) >> 1);
    }
  }
  while (d(r)) --r;
  answ(r);
}
