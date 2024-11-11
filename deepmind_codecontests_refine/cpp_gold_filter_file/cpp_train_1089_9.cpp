#include <bits/stdc++.h>
using namespace std;
struct node {
  long long x;
  long long y;
};
long long gcd(long long a, long long b) {
  return b == 0 ? a : a > b ? gcd(b, a % b) : gcd(a, b % a);
}
bool myfunc(struct node a, struct node b) {
  if (a.x == b.x) {
    return a.y < b.y;
  } else {
    return a.x < b.x;
  }
}
long long po[60];
long long rec(int turn, long long h, long long n) {
  if (h == 0) {
    return 0;
  } else {
    if (n > po[h - 1]) {
      if (turn == 1) {
        return rec((turn + 1) % 2, h - 1, n - po[h - 1]) + 1;
      } else {
        return rec(turn, h - 1, n - po[h - 1]) + (po[h]);
      }
    } else {
      if (turn == 1) {
        return rec(turn, h - 1, n) + (po[h]);
      } else {
        return rec((turn + 1) % 2, h - 1, n) + 1;
      }
    }
  }
}
int main() {
  long long h, n;
  cin >> h >> n;
  long long i;
  po[0] = 1;
  for (i = 1; i <= 60; i++) {
    po[i] = po[i - 1] * 2;
  }
  long long ans = rec(0, h, n);
  cout << ans << endl;
  return 0;
}
