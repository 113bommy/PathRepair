#include <bits/stdc++.h>
using namespace std;
void solve(istream &in, ostream &out);
int main() {
  ios::sync_with_stdio(false);
  solve(cin, cout);
  return 0;
}
static inline int g1(int n) {
  if (n == 1 || n == 3) {
    return 1;
  }
  if (n % 2) {
    return 0;
  }
  int h1 = g1(n - 1);
  int h2 = g1(n / 2);
  if (h1 > h2) {
    swap(h1, h2);
  }
  if (h1 > 0) {
    return 0;
  }
  if (h2 == 1) {
    return 2;
  }
  return 1;
}
static inline int g0(int n) {
  if (n == 1) {
    return 1;
  }
  return 1 - n % 2;
}
void solve(istream &in, ostream &out) {
  int n, k;
  in >> n >> k;
  int ans = 0;
  if (k % 2) {
    for (int i = 0, a; i < n; ++i) {
      in >> a;
      ans ^= g1(a);
    }
  } else {
    for (int i = 0, a; i < n; ++i) {
      in >> a;
      ans ^= g0(a);
    }
  }
  if (ans) {
    out << "Kevin" << endl;
  } else {
    out << "Nicky" << endl;
  }
}
